#include "StdAfx.h"
#include "CenterCaption.h"
#include "resource.h"
#include "MainFrame.h"
#include ".\centercaption.h"

CCenterCaption::CCenterCaption(void)
{
}

CCenterCaption::~CCenterCaption(void)
{
}
BEGIN_MESSAGE_MAP(CCenterCaption, CPanel)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CCenterCaption::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPanel::OnPaint()
	CBrush hbr;
	hbr.CreateSolidBrush(RGB(0,255,0));
	CRect rtClient;
	GetClientRect(&rtClient);
	m_imgCenterCaption.Draw(dc.m_hDC, rtClient);
	
}

void CCenterCaption::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame->IsZoomed())
	{
		pMainFrame->SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
	}
	else
	{
		pMainFrame->SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	}

	CPanel::OnLButtonDblClk(nFlags, point);
}

void CCenterCaption::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	CPanel::OnLButtonDown(nFlags, point);
}

int CCenterCaption::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if(m_imgCenterCaption.IsNull())
	{
		m_imgCenterCaption.LoadFromResource(AfxGetInstanceHandle(), IDB_CAPTION);
	}
	return 0;
}
