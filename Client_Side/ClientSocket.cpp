#include "stdafx.h"
#include "ClientSocket.h"


CClientSocket::CClientSocket()
{
}


CClientSocket::~CClientSocket()
{
}

BOOL CClientSocket::Login(LPSTR lpBuff, int nlen, char account[8], char password[8])
{
	HEADER head;
	head.Type = MSG_LOGIN;
	head.ContentLength = nlen;
	memset(head.FromUser, 0, sizeof(head.FromUser));
	memset(head.ToUser, 0, sizeof(head.ToUser));
	memset(head.GroupID, 0, sizeof(head.GroupID));
	strcpy_s(head.FromUser, "11111");
	strcpy_s(head.ToUser, "sdf");
	strcpy_s(head.GroupID, "1231");

	//memset(head.Account, 0, sizeof(head.Account));
	//memset(head.Password, 0, sizeof(head.Password));
	//strcpy_s(head.Account, account);
	//strcpy_s(head.Password, password);
	int nSend = 0;
	if ((nSend = Send(&head, sizeof(head))) == SOCKET_ERROR)
		return false;
	if ((nSend = Send(lpBuff, nlen)) == SOCKET_ERROR)
		return false;
	return TRUE;
}


void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	HEADER head;
	char *pHead = NULL;
	pHead = new char[sizeof(head)];
	memset(pHead, 0, sizeof(head));
	Receive(pHead, sizeof(head));

	head.Type = ((LPHeader)pHead)->Type;
	head.ContentLength = ((LPHeader)pHead)->ContentLength;
	delete pHead;
	pHead = NULL;
	char* pBuff = NULL;
	pBuff = new char[head.ContentLength];
	if (!pBuff)
	{
		AfxMessageBox(_T("内存不足"));
		return;
	}
	memset(pBuff, 0, sizeof(char)*head.ContentLength);
	if (head.ContentLength != Receive(pBuff, head.ContentLength))
	{
		AfxMessageBox(_T("收到的数据有误"));
		delete pBuff;
		return;
	}
	switch (head.Type)
	{
	case MSG_FLOGIN:
	{
		m_isLogin = false;
	}
	case MSG_TLOGIN:
	{
		m_isLogin = true;
	}
	default:
		break;
	}
	CSocket::OnReceive(nErrorCode);
}


