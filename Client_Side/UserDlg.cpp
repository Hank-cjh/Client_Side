// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client_Side.h"
#include "UserDlg.h"
#include "afxdialogex.h"


// CUserDlg 对话框

IMPLEMENT_DYNAMIC(CUserDlg, CDialogEx)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_USER, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialogEx)
END_MESSAGE_MAP()


// CUserDlg 消息处理程序
