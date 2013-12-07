#include "StdAfx.h"
#include "RightCaption.h"
#include "MainFrame.h"
/*#include ".\rightcaption.h"*/
#include "resource.h"
#define IDC_BTN_MIN		1004
#define IDC_BTN_MAX		1005
#define IDC_BTN_CLOSE	1006
CRightCaption::CRightCaption(void)
{
}

CRightCaption::~CRightCaption(void)
{
}
BEGIN_MESSAGE_MAP(CRightCaption, CPanel)
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BTN_MIN, OnMinButtonClicked)
	ON_BN_CLICKED(IDC_BTN_MAX, OnMaxButtonClicked)
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnCloseButtonClicked)
END_MESSAGE_MAP()

void CRightCaption::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPanel::OnPaint()
	CBrush hbr;
	hbr.CreateSolidBrush(RGB(0,0,255));
	CRect rtClient;
	GetClientRect(&rtClient);
	m_imgRightCaption.Draw(dc.m_hDC, rtClient);
}

void CRightCaption::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->SendMessage(WM_NCLBUTTONDBLCLK, HTCAPTION, 0);
	CPanel::OnLButtonDblClk(nFlags, point);
}

void CRightCaption::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	pMainFrame->SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	CPanel::OnLButtonDown(nFlags, point);
}

int CRightCaption::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rectClient;
	GetClientRect(rectClient);
	if (m_imgRightCaption.IsNull())
	{
		m_imgRightCaption.LoadFromResource(AfxGetInstanceHandle(), IDB_CAPTION);
	}
	// TODO:  在此添加您专用的创建代码
	m_closeBtn.Create(CRect(rectClient.right-30, 2, rectClient.right - 5, 19), this, IDC_BTN_CLOSE);
	m_maxBtn.Create(CRect(rectClient.right-55, 2, rectClient.right - 30, 19), this, IDC_BTN_MAX);
	m_minBtn.Create(CRect(rectClient.right-80, 2, rectClient.right - 55, 19), this, IDC_BTN_MIN);
	m_closeBtn.SetBitmap(IDB_CLOSE);
	m_maxBtn.SetBitmap(IDB_MAX);
	m_minBtn.SetBitmap(IDB_MIN);

	return 0;
}

void CRightCaption::OnMinButtonClicked()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame != NULL)
	{
		pMainFrame->SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
	}
}
void CRightCaption::OnMaxButtonClicked()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame != NULL)
	{
		if (pMainFrame->IsZoomed())
		{
			pMainFrame->SendMessage(WM_SYSCOMMAND, SC_RESTORE, 0);
		}
		else
		{
			pMainFrame->SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		}
		
	}
}
void CRightCaption::OnCloseButtonClicked()
{
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	if (pMainFrame != NULL)
	{
		pMainFrame->SendMessage(WM_SYSCOMMAND, SC_CLOSE, 0);
	}
}
