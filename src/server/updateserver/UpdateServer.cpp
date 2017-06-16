//--------------------------------------------------------------------------------
// 
// Filename    : UpdateServer.cpp 
// Written By  : Reiot
// 
//--------------------------------------------------------------------------------

// include files
#include <fstream>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <map>

#include "UpdateServer.h"
#include "Assert.h"
#include "SystemAPI.h"
#include "Properties.h"
#include "UpdateServerPlayer.h"
#include "Timeval.h"


//--------------------------------------------------------------------------------
//
// constructor
//
//--------------------------------------------------------------------------------
UpdateServer::UpdateServer ()
	throw ( Error )
: m_pServerSocket(NULL)
{
	__BEGIN_TRY

	try {

		// create server socket
		m_pServerSocket = new ServerSocket( g_pConfig->getPropertyInt("Port") );

	} catch ( NoSuchElementException & nsee ) {

		throw Error(nsee.toString());

	}

	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// destructor
//
//--------------------------------------------------------------------------------
UpdateServer::~UpdateServer ()
	throw ( Error )
{
	__BEGIN_TRY

	if ( m_pServerSocket != NULL ) {
		delete m_pServerSocket;
		m_pServerSocket = NULL;
	}

	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// initialize game server
//
//--------------------------------------------------------------------------------
void UpdateServer::init ()
	 throw ( Error )
{
	__BEGIN_TRY

	sysinit();

	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// start game server
//
//--------------------------------------------------------------------------------
void UpdateServer::start ()
	 throw ( Error )
{
	__BEGIN_TRY

	run();
		
	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// stop game server
//
//--------------------------------------------------------------------------------
void UpdateServer::stop ()
	 throw ( Error )
{
	__BEGIN_TRY
	__END_CATCH
}


//--------------------------------------------------------------------------------
//
// main loop
//
//--------------------------------------------------------------------------------
void UpdateServer::run ()
	 throw ()
{
	try {

		int p[2];
		const int exitFlagSize = 1;
		char exitFlag[exitFlagSize];

		// pipe�� child�� ����.. ���������. by sigi. 2002.11.9
		if (pipe(p) < 0)
		{
			//cout << "cannot create pipe" << endl;
			exit(0);
		}

		// nonblock ���
		int flags = fcntl( p[0] , F_GETFL , 0 );
		flags |= O_NONBLOCK;
		fcntl( p[0] , F_SETFL , flags );

		// ���� ������� client ����
		int nClient = 0;
		int maxClient = g_pConfig->getPropertyInt("MaxClient");

		int connectClient = 0;
		int disconnectClient = 0;

		// fork �Ѱ��� exception catch�Ҷ� ���� by sigi. 2002.11.9
		bool bBeforeFork = false;

		int tick = 0;

		Timeval currentTime;
		Timeval nextTime;

		getCurrentTime(currentTime);
		nextTime.tv_sec = currentTime.tv_sec + 10;

		map<string, int> IPs;
		map<string, int> DenyLists;

		// main loop
		while ( true ) {

			try {
				//cout << endl << "waiting for connection..." << endl;

				// blocking client socket
				Socket * pSocket = NULL;
				try {
					pSocket = m_pServerSocket->accept();
				} catch ( Throwable & t ) {
					continue;
				} catch ( exception& e ) {
					cout << e.what() << endl;
					filelog("parentExceptionLog.txt", "%s", e.what());
					continue;
				}

				if( pSocket == NULL ) continue;

				//cout << "Accept..." << endl;

	/*
				pSocket->setNonBlocking(false);
				// ������ ���۸� �ø���.
				pSocket->setSendBufferSize(60000000);
				pSocket->setReceiveBufferSize(100000000);
	*/

				//cout << "NEW CONNECTION FROM " << pSocket->getHost().c_str() << ":" << pSocket->getPort() << endl;

				//cout << "Socket Send Buffer Size " << pSocket->getSendBufferSize() << endl;
				//cout << "Socket Receive Buffer Size " << pSocket->getReceiveBufferSize() << endl;

				UpdateServerPlayer * pPlayer = new UpdateServerPlayer( pSocket );
				pPlayer->setPlayerStatus( USPS_BEGIN_SESSION );

				const string& IP = pSocket->getHost();

				map<string, int>::iterator itr = IPs.find(IP);
				if (itr==IPs.end())
				{
					IPs[IP] = 1;	
				}
				else
				{
					itr->second ++;
				}

				map<string, int>::iterator itrdeny = DenyLists.find(IP);
				if (itrdeny!=DenyLists.end())
				{
					delete pSocket;
					continue;
				}


				// child�� ����ȰŸ� üũ���ش�.	 by sigi. 2002.11.9
				int nExitClient = 0;
				while (1)
				{
					int nRead = read(p[0], exitFlag, exitFlagSize);

					// ����� ���� ������.
					if (nRead==-1)
						break;

					// �ϳ��� child�� ����ƴٴ� ������.
					nExitClient ++;
					disconnectClient ++;
				}

				nClient -= nExitClient;

				if (nExitClient>0)
				{
					//cout << "----------- exit -------------- : nExitClient = " << nExitClient << endl;
				}

				//if (++tick % 500==0)
				getCurrentTime(currentTime);

				if (nextTime.tv_sec < currentTime.tv_sec)
				{
					// ����� ����
					map<string, int>::const_iterator itr = IPs.begin();
					for (; itr!=IPs.end(); itr++)
					{
						const string& IP = itr->first;
						int count = itr->second;

						if( count > g_pConfig->getPropertyInt("TryingNumber") ) {
							DenyLists[IP] = count;
							filelog("denylist.txt", "%s", IP.c_str() );
						}

						filelog("userCountLog.txt", "%s = %d", IP.c_str(), count);
					}
					IPs.clear();

					filelog("userCountLog.txt", "##### Total in 10 sec ##### +%d -%d = %d", connectClient, disconnectClient, nClient );

					connectClient = 0;
					disconnectClient = 0;
					tick = 0;

					nextTime.tv_sec = currentTime.tv_sec + 10;
				}


				// ������ ���� �д�. by sigi. 2002.11.9
				if (nClient > maxClient)
				{
					//cout << "Not Accept More: " << nClient << "/" << maxClient << endl;
					delete pSocket;
					pSocket = NULL;

					continue;
				}

				//--------------------------------------------------------------------------------
				// ��Ȱ�� ������Ʈ�� ��ؼ�, select ���� fork()�� �����ؼ� 1:1 ������ �����Ѵ�.
				//--------------------------------------------------------------------------------
				bool bBeforeFork = true;
				nClient ++;
				connectClient ++;

				//cout << "Before fork" << endl;

				if ( SystemAPI::fork_ex() == 0 ) { // case of child

					//cout << "FORK PROCESS[" << getpid() << "] HANDLE " << pSocket->getHost() << endl;

					try {
						while ( true ) {
							//cout << "client loop" << endl;
							pPlayer->processInput();
							pPlayer->processCommand();
							pPlayer->processOutput();

							usleep( 1000 );
						}
					} catch ( ProtocolException & pe ) {
						//cout << ce.toString() << endl;
					} catch ( ConnectException & ce ) {
						//cout << ce.toString() << endl;
					} catch ( Throwable & t ) {
						filelog("childExceptionLog.txt", "%s", t.toString().c_str());
						cout << t.toString() << endl;
					}

					delete pSocket;

					//cout << "CHILD PROCESS EXIT" << endl;

					// ����� ����� ��μ����� ����Ѵ�.
					write(p[1], exitFlag, exitFlagSize);	// parent���� �˸���. by sigi. 2002.11.9
					exit(0);

				} else { // case of parent
					//cout << "PARENT CLOSE CLIENT SOCKET" << endl;
					delete pSocket;
				}

				bBeforeFork = false;

				
				usleep( 200 );


			} catch (Error& e) {
				// fork�� �ȵ� ����
				if (bBeforeFork)
				{
					// ����
					filelog("parentExceptionLog.txt", "%s", e.toString().c_str());
				}
				else
				{
					filelog("parentExceptionLog.txt", "%s", e.toString().c_str());
					throw;
				}
			}
		}//while
	
	} catch ( Throwable & t ) {
		filelog("parentExceptionLog.txt", "%s", t.toString().c_str());
		cout << t.toString() << endl;
	} catch ( exception & e ) {
		filelog("parentExceptionLog.txt", "%s", e.what());
		cout << e.what() << endl;
	}

	cout << "==============================================" << endl;
	cout << "==========     UpdateServer exit   ===========" << endl;
	cout << "==============================================" << endl;
}


//--------------------------------------------------------------------------------
//
// �ý��� ������ �ʱ�ȭ
//
//--------------------------------------------------------------------------------
void UpdateServer::sysinit()
	throw ( Error )
{
	__BEGIN_TRY

	signal( SIGPIPE , SIG_IGN );	// �̰Ŵ� �� �߻��� ��
	signal( SIGALRM , SIG_IGN );	// �˶� �ϴ� ������ ����, ���ǻ�
	signal( SIGCHLD , SIG_IGN );	// fork �ϴ� ������ ����, ���ǻ�

	__END_CATCH
}


//--------------------------------------------------------------------------------
// 
// ���߿� �ַܼ� ������ �ʿ䰡 ������ ��ŭ ������� �Ǹ�, 
// �� �Լ��� ȣ���ϵ��� �Ѵ�.
// 
//--------------------------------------------------------------------------------
void UpdateServer::goBackground ()
	throw ( Error )
{
	__BEGIN_TRY

	int forkres = SystemAPI::fork_ex();

	if ( forkres == 0 ) {
		// case of child process
		close( 0 );
		close( 1 );
		close( 2 );
	} else {
		// case of parent process
		exit(0);
	}

	__END_CATCH
}


// global variable declaration
UpdateServer * g_pUpdateServer = NULL;
