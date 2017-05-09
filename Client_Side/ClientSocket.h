#pragma once

#include "afxsock.h"
#include "Header.h"
#include "UserDlg.h"
class CClientSocket :
	public CSocket
{
public:
	CClientSocket();
	~CClientSocket();
	BOOL Login(LPSTR lpBuff, int nlen, char account[8], char password[8]);
	virtual void OnReceive(int nErrorCode);
	BOOL m_isLogin = false;
}; // !_CLIENTSOCKET_H_

