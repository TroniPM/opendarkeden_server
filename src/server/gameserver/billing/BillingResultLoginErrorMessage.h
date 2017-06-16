#ifndef __BILLING_RESULT_LOGIN_ERROR_MESSAGE_H__
#define __BILLING_RESULT_LOGIN_ERROR_MESSAGE_H__

#include "Types.h"
#include "BillingInfo.h"
#include "Utility.h"
#include <string>
#include <map>

class BillingResultLoginErrorMessage
{
public:
	static BillingResultLoginErrorMessage* Instance();

	string getMessage( int index ) const;

protected:
	BillingResultLoginErrorMessage();

	void initMessage();

private:
	static BillingResultLoginErrorMessage* _instance;

	typedef map<int, string>			HashMapMessage;
	typedef HashMapMessage::iterator		HashMapMessageItr;
	typedef HashMapMessage::const_iterator	HashMapMessageConstItr;

	HashMapMessage m_Messages;
};


BillingResultLoginErrorMessage* BillingResultLoginErrorMessage::_instance = 0;

BillingResultLoginErrorMessage* BillingResultLoginErrorMessage::Instance()
{
	if ( _instance == 0 )
	{
		_instance = new BillingResultLoginErrorMessage;
	}
	
	return _instance;
}

BillingResultLoginErrorMessage::BillingResultLoginErrorMessage()
{
	initMessage();
}

void BillingResultLoginErrorMessage::initMessage()
{
	m_Messages[BILLING_RESULT_LOGIN_DB_ERROR]		= "DB�� ����� �� ����ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_NETWORK_ERROR]	= "��Ʈ��ũ�� ����� �߻��Ͽ���ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_NO_CASH]		= "�ܾ��� ����մϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_NO_SESSION]		= "������ ����ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_BAD_PACKET]		= "��� ���� �ʴ� ��Ŷ";
	m_Messages[BILLING_RESULT_LOGIN_COM_ERROR]		= "COM ����";
	m_Messages[BILLING_RESULT_LOGIN_NO_RESPONSE]	= "����� �ð����� ����� ����ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_NO_MACHINE]		= "�ش� ������ ����� �� ����ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_BAD_GAME_NO]	= "���� ������ ���ϵ� ���ӹ�ȣ�� �ٸ��ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_ACCOUNT_ERROR]	= "���� ��ī��Ʈ�� ������ ����";
	m_Messages[BILLING_RESULT_LOGIN_DENY]			= "�ش� ���ӿ� ���� �Ұ��� ( ��� ����� ��� )";
	m_Messages[BILLING_RESULT_LOGIN_TIME_OVER]		= "�ȿ �Ⱓ�� ����";
	m_Messages[BILLING_RESULT_LOGIN_BUSY]			= "���� ���� �����ڰ� ����ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_UNKNOWN_ERROR]	= "��� ���� ��� ��� ��ȣ�Դϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_IP_COM_ERROR]	= "IP�� Ȯ���ϴ��� COM������ �߻��Ͽ���ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_IP_ERROR]		= "�ش� IP�� ����� �������� ����� ����մϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_KEY_COM_ERROR]	= "����Ű�� Ȯ���ϴ� �� COM������ �߻��Ͽ���ϴ�.";
	m_Messages[BILLING_RESULT_LOGIN_NO_KEY]			= "����Ű�� ã�� ���߽�ϴ�.";
}

string BillingResultLoginErrorMessage::getMessage( int index ) const
{
	HashMapMessageConstItr itr = m_Messages.find( index );

	if ( itr == m_Messages.end() )
	{
		filelog( "BillingResultLoginErrorMessage.txt", "No Message ID : %d", index );
		return "";
	}

	return itr->second;
}

#endif
