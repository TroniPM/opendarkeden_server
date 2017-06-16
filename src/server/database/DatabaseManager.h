//////////////////////////////////////////////////////////////////////////////
// Filename    : DatabaseManager.h
// Written By  : elca
// Description : ����Ÿ���̽� �Ŵ���
//////////////////////////////////////////////////////////////////////////////

#ifndef __DATABASE_MANAGER_H__
#define __DATABASE_MANAGER_H__

#include "Types.h"
#include "Exception.h"
#include <map>
#include "Connection.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class DatabaseManager;
//////////////////////////////////////////////////////////////////////////////

class DatabaseManager 
{
public:
	DatabaseManager() throw();
	~DatabaseManager() throw();
	
public:
	void init() throw(Error);
	void addConnection(int TID, Connection * pConnection) throw(DuplicatedException);
	void addDistConnection(int TID, Connection * pConnection) throw(DuplicatedException);
	void addCBillingConnection(int TID, Connection * pConnection) throw(DuplicatedException);
//	void addPCRoomConnection(int TID, Connection * pConnection) throw(DuplicatedException);

	Connection* getConnection(const string& ip) throw(NoSuchElementException);
	Connection* getDistConnection(const string& ip) throw(NoSuchElementException);
	Connection* getCBillingConnection(const string& ip) throw(NoSuchElementException);
//	Connection* getPCRoomConnection(const string& ip) throw(NoSuchElementException);
	Connection* getUserInfoConnection(void) throw() { return m_pUserInfoConnection; }
	void	executeDummyQuery(Connection* pConnection) throw (Error);

	//--------------------------------------------------------------------
	// * elca's NOTE
	// �α��� �������� ĳ������ ����� ������ ��������� �˾Ƴ��� ��Ͽ�
	// DB�� �ġ�� �˾Ƴ� �´�.
	// ���� DB������ DB�� �ġ�� �����ϴ� Table�� ����ؾ� �Ѵ�.
	// GameServerIP�� �̾� �� ���� ������ DB�� GameServer�� �ٸ� ���츦
	// �����Ͽ� Ȯ�强� �����Ѵ�.
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	// * elca's NOTE
	// �� ���� ������ ���� Parent/Main DB��� �˸� �ȴ�.
	// ���� DB ������ ���� ���̵��� ����� 0 ���̶��� ����ϰ�
	// ���� DB ������ ���� 0 �� ���ڷ� �ѱ���.
	// ���� ������ ���� �� 0 ���� Ŀ�ؼǸ� ������ ����� �ȴ�.
	// Ȥ�ó� �ϴ� ������ ����� �ֱ� ������ ���� �ٸ� Ŀ�ؼ�� ���� �ʵ���
	// ���� �ϵ��� �Ѵ�.
	// �Ϲ� ���� �������� ���� ������ ���� ������� �ֱ� ������
	// �Ű澲�� �ʵ��� �Ѵ�.
	//--------------------------------------------------------------------
	Connection* getConnection( int TID ) throw(NoSuchElementException);
//	void addConnection(WorldID_t WorldID, Connection * pConnection) throw(DuplicatedException);

private:
	// �� �����庰�� ����ϴ� DB ����
	map<int, Connection*> m_Connections;

	// �� �����庰�� ����ϴ� Distribute DB ����
	map<int, Connection*> m_DistConnections;

//	map<WorldID_t, Connection*> m_WorldConnections;
	map<int, Connection*> m_WorldConnections;

	// �� �����庰�� ����ϴ� CBilling DB ����
	map<int, Connection*> m_CBillingConnections;

	// PC�� ���տ� DB ����
//	map<int, Connection*> m_PCRoomConnections;

	// �� ���庰�� ����ϴ� DB ����

	// ��� ó� �����Ǵ� �⺻ DB ����
	Connection* m_pDefaultConnection;

	// ��� ó� �����Ǵ� �� ��� DB�� �⺻ ����
	Connection* m_pWorldDefaultConnection;

	// ������ ���� ���� DB ����
	Connection* m_pUserInfoConnection;

	Connection* m_pDistConnection;

	// PC�� ���տ� DB ���� default. �α��� ������ ����.
//	Connection* m_pPCRoomConnection;

	mutable Mutex m_Mutex;
};

extern DatabaseManager * g_pDatabaseManager;

#endif
