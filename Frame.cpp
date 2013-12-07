// Fram.cpp : 定义应用程序的类行为。
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


// CFramApp 构造

CFramApp::CFramApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CFramApp 对象

CFramApp theApp;


// CFramApp 初始化

BOOL CFramApp::InitInstance()
{
	CWinApp::InitInstance();

	CMainFram *pMainFram = new CMainFram();

	ASSERT(pMainFram != NULL);

	//如果在win7下面指定WS_POPUPWINDOW则边框去不掉
	pMainFram->CreateEx(0,_T("MAINFRAM"),_T(""),WS_VISIBLE|WS_THICKFRAME|WS_POPUPWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL);

	m_pMainWnd = pMainFram;

	pMainFram->ShowWindow(SW_SHOW);
	pMainFram->UpdateWindow();

	return TRUE;
}
