// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Client_Side.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedbtnlogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (m_sAccount.IsEmpty())
	{
		AfxMessageBox(_T("�˺Ų���Ϊ��"));
	}
	if (m_sPassword.IsEmpty())
	{
		AfxMessageBox(_T("���벻��Ϊ��"));
	}
	CClientSocket*m_pSocket = theApp.GetMainSocket();
	char* lpIP = "192.168.137.1";//��������IP
	CString strIP(lpIP);
	if (!m_pSocket->Connect(strIP.GetBuffer(0), 10000))
	{
		AfxMessageBox(_T("���ӷ�����ʧ�ܣ�"));
		return;
	}
	else
	{
		AfxMessageBox(_T("���ӷ������ɹ�"));
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
		AfxMessageBox(_T("���ͳɹ�"));
	};
	if (m_pSocket->m_isLogin)
	{
		CUserDlg*pUserDlg;//�û�����
		pUserDlg = new CUserDlg();
		pUserDlg->DoModal();
	}
	else
	{
		m_pSocket->Close();
	}
	
}
