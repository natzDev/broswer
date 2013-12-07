#include "StdAfx.h"
#include ".\toolpanel.h"
#include "resource.h"

CToolPanel::CToolPanel(void)
{
}

CToolPanel::~CToolPanel(void)
{
}
BEGIN_MESSAGE_MAP(CToolPanel, CPanel)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int CToolPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if (m_imgTool.IsNull())
	{
		m_imgTool.LoadFromResource(AfxGetInstanceHandle(), IDB_TOOLBAR);
	}
	else
	{
		return 0;
	}
	m_wndMainToolBar.Create(_T(""), WS_CHILD | WS_VISIBLE, CRect(0, 0, 260, 51), this, IDC_MAINTOOLBAR);
	m_wndAddressBar.Create(_T(""), WS_CHILD | WS_VISIBLE, CRect(260, 0, lpCreateStruct->cx - 200, 51), this, IDC_ADDRESSBAR);
	return 0;
}

void CToolPanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPanel::OnPaint()
	if (m_imgTool.IsNull())
	{
		return;
	}
	else
	{
		CRect rect;
		GetClientRect(rect);
		m_imgTool.Draw(dc.m_hDC, rect);
	}
}

void CToolPanel::OnSize(UINT nType, int cx, int cy)
{
	CPanel::OnSize(nType, cx, cy);
	if (m_wndAddressBar.m_hWnd == NULL) return;
	if (m_wndAddressBar.m_hWnd == NULL) return;
	m_wndMainToolBar.MoveWindow(CRect(0, 0, 260, 51));
	m_wndAddressBar.MoveWindow(CRect(260, 0, cx - 200, 51));
}
