
// Client_Side.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


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

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CClient_SideApp theApp;