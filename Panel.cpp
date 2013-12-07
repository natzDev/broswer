// BasePanel.cpp : 实现文件
//

#include "stdafx.h"
#include "Frame.h"
#include "Panel.h"
#include ".\panel.h"


// CPanel

IMPLEMENT_DYNAMIC(CPanel, CWnd)

CPanel::CPanel()
{

}

CPanel::~CPanel()
{
}


BEGIN_MESSAGE_MAP(CPanel, CWnd)
END_MESSAGE_MAP()



// CPanel 消息处理程序

BOOL CPanel::Create( LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext )
{
	return CWnd::Create("Panel",lpszWindowName,dwStyle,rect,pParentWnd,nID,pContext);
}

BOOL CPanel::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此添加专用代码和/或调用基类
	HINSTANCE hist = AfxGetInstanceHandle();

	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	if (GetClassInfoEx(hist,cs.lpszClass,&wcex))
	{
		return TRUE;
	}

	wcex.cbClsExtra = 0;
	wcex.cbSize = sizeof(wcex);
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
	wcex.hIcon = LoadIcon(hist,MAKEINTRESOURCE(IDR_MAINFRAME));
	wcex.hIconSm = LoadIcon(hist,MAKEINTRESOURCE(IDR_MAINFRAME));
	wcex.hInstance = hist;
	wcex.lpfnWndProc = AfxWndProc;
	wcex.lpszClassName = cs.lpszClass;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;

	if (!RegisterClassEx(&wcex))
	{
		return FALSE;
	}

	return  TRUE;

}
