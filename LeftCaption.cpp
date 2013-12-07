#include "StdAfx.h"
#include "LeftCaption.h"
#include "MainFrame.h"
#include "resource.h"

CLeftCaption::CLeftCaption(void)
{
}

CLeftCaption::~CLeftCaption(void)
{
}
BEGIN_MESSAGE_MAP(CLeftCaption, CPanel)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
END_MESSAGE_MAP()

void CLeftCaption::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPanel::OnPaint()
	CBrush hbr;
	hbr.CreateSolidBrush(RGB(255,0,0));
	CRect rtClient;
	GetClientRect(&rtClient);
	m_imgLeftCaption.Draw(dc.m_hDC, rtClient);
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame)
	{
		HICON hIcon = (HICON)GetClassLong(pMainFrame->m_hWnd, GCL_HICONSM);
		if (hIcon)
		{
			::DrawIconEx(dc.m_hDC, 4, 4, hIcon, 16, 16, 0, 0,DI_NORMAL);
		}
		CString strText;
		pMainFrame->GetWindowText(strText);
		if (strText.IsEmpty())
			return;
		CRect rcText;
		rcText= rtClient;
		rcText.left = 25;
		dc.SetBkMode(TRANSPARENT);
		dc.DrawText(strText, rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE | DT_WORD_ELLIPSIS);
		
	}
}

void CLeftCaption::OnLButtonDblClk(UINT nFlags, CPoint point)
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

void CLeftCaption::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);

	CPanel::OnLButtonDown(nFlags, point);
}

void CLeftCaption::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame)
	{
		CMenu* pSysMenu = pMainFrame->GetSystemMenu(0);
		int nID = pSysMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON | TPM_RETURNCMD, point.x, point.y, pMainFrame);
		pMainFrame->SendMessage(WM_SYSCOMMAND, nID, 0);
	}
}

int CLeftCaption::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	if(m_imgLeftCaption.IsNull())
	{
		m_imgLeftCaption.LoadFromResource(AfxGetInstanceHandle(), IDB_CAPTION);
	}
	return 0;
}
