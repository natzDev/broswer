// Broswer.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Broswer.h"
#include "MainFrame.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBroswerApp

BEGIN_MESSAGE_MAP(CBroswerApp, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


// CBroswerApp ����

CBroswerApp::CBroswerApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CBroswerApp ����

CBroswerApp theApp;


// CBroswerApp ��ʼ��

BOOL CBroswerApp::InitInstance()
{
	CWinApp::InitInstance();

	m_pMainWnd = new CMainFrame();

	ASSERT(m_pMainWnd != NULL);

	//�����win7����ָ��WS_POPUPWINDOW��߿�ȥ����
	m_pMainWnd->CreateEx(0,_T("MAINFRAM"),_T("���������"),WS_VISIBLE|WS_THICKFRAME|WS_POPUPWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL);
	m_pMainWnd->CenterWindow();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

int CBroswerApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	return CWinApp::ExitInstance();
}
