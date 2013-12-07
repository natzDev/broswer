// Fram.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Fram.h"
#include "MainFram.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFramApp

BEGIN_MESSAGE_MAP(CFramApp, CWinApp)
END_MESSAGE_MAP()


// CFramApp ����

CFramApp::CFramApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CFramApp ����

CFramApp theApp;


// CFramApp ��ʼ��

BOOL CFramApp::InitInstance()
{
	CWinApp::InitInstance();

	CMainFram *pMainFram = new CMainFram();

	ASSERT(pMainFram != NULL);

	//�����win7����ָ��WS_POPUPWINDOW��߿�ȥ����
	pMainFram->CreateEx(0,_T("MAINFRAM"),_T(""),WS_VISIBLE|WS_THICKFRAME|WS_POPUPWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL);

	m_pMainWnd = pMainFram;

	pMainFram->ShowWindow(SW_SHOW);
	pMainFram->UpdateWindow();

	return TRUE;
}
