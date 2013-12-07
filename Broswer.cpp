// Broswer.cpp : 定义应用程序的类行为。
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


// CBroswerApp 构造

CBroswerApp::CBroswerApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBroswerApp 对象

CBroswerApp theApp;


// CBroswerApp 初始化

BOOL CBroswerApp::InitInstance()
{
	CWinApp::InitInstance();

	m_pMainWnd = new CMainFrame();

	ASSERT(m_pMainWnd != NULL);

	//如果在win7下面指定WS_POPUPWINDOW则边框去不掉
	m_pMainWnd->CreateEx(0,_T("MAINFRAM"),_T("奔腾浏览器"),WS_VISIBLE|WS_THICKFRAME|WS_POPUPWINDOW,\
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL);
	m_pMainWnd->CenterWindow();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

int CBroswerApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
	return CWinApp::ExitInstance();
}
