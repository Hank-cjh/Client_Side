// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client_Side.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN, pParent)
	, m_sAccount(_T(""))
	, m_sPassword(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_editAccount, m_sAccount);
	DDX_Text(pDX, IDC_editPassword, m_sPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_btnLogin, &CLoginDlg::OnBnClickedbtnlogin)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedbtnlogin()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if (m_sAccount.IsEmpty())
	{
		AfxMessageBox(_T("账号不能为空"));
	}
	if (m_sPassword.IsEmpty())
	{
		AfxMessageBox(_T("密码不能为空"));
	}
	CClientSocket*m_pSocket = theApp.GetMainSocket();
	char* lpIP = "192.168.137.1";//服务器端IP
	CString strIP(lpIP);
	if (!m_pSocket->Connect(strIP.GetBuffer(0), 10000))
	{
		AfxMessageBox(_T("连接服务器失败！"));
		return;
	}
	else
	{
		AfxMessageBox(_T("连接服务器成功"));
	}
	char account[8];
	char password[8];
	memset(account, 0, sizeof(account));
	memset(password, 0, sizeof(password));
	WideCharToMultiByte(CP_OEMCP, 0, (LPCTSTR)m_sAccount, -1, account, 260, 0, false);
	WideCharToMultiByte(CP_OEMCP, 0, (LPCTSTR)m_sPassword, -1, password, 260, 0, false);
	char*pBuff = new char[m_sAccount.GetLength() * 2 + 1];
	memset(pBuff, 0, m_sAccount.GetLength() * 2);
	
	if (m_pSocket->Login(pBuff, m_sAccount.GetLength() * 2 + 1, account, password)) 
	{
		AfxMessageBox(_T("发送成功"));
	};
	if (m_pSocket->m_isLogin)
	{
		CUserDlg*pUserDlg;//用户界面
		pUserDlg = new CUserDlg();
		pUserDlg->DoModal();
	}
	else
	{
		m_pSocket->Close();
	}
	
}
