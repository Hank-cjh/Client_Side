
// Client_Side.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "ClientSocket.h"
#include "LoginDlg.h"

// CClient_SideApp: 
// �йش����ʵ�֣������ Client_Side.cpp
//

class CClient_SideApp : public CWinApp
{
public:
	CClient_SideApp();

// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CClientSocket*GetMainSocket()const;
	CClientSocket*m_pSocket;
// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CClient_SideApp theApp;