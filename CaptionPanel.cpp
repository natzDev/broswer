#include "StdAfx.h"
#include "CaptionPanel.h"
// #include ".\captionview.h"

CCaptionPanel::CCaptionPanel(void)
{
	m_leftCaption.m_hWnd = NULL;
	m_centerCaption.m_hWnd = NULL;
	m_RightCaption.m_hWnd = NULL;
}

CCaptionPanel::~CCaptionPanel(void)
{
}
BEGIN_MESSAGE_MAP(CCaptionPanel, CPanel)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int CCaptionPanel::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CRect rtClient;
	GetClientRect(&rtClient);
	if(m_leftCaption.m_hWnd == NULL)
	{
		m_leftCaption.Create(_T("LeftCaption"),WS_CHILD|WS_VISIBLE,CRect(0, 0, lpCreateStruct->cx - 290, lpCreateStruct->cy),this,10001);
	}
	if(m_centerCaption.m_hWnd == NULL)
	{
		m_centerCaption.Create(_T("CenterCaption"),WS_CHILD|WS_VISIBLE,CRect(lpCreateStruct->cx - 290, 0, lpCreateStruct->cx - 100, lpCreateStruct->cy),this,10002);
	}
	if(m_RightCaption.m_hWnd == NULL)
	{
		m_RightCaption.Create(_T("LeftCaption"),WS_CHILD|WS_VISIBLE,CRect(lpCreateStruct->cx - 100, 0, lpCreateStruct->cx, lpCreateStruct->cy),this,10003);
	}

	return 0;
}

void CCaptionPanel::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CPanel::OnPaint()
	CBrush hbr;
	hbr.CreateSolidBrush(RGB(255,255,0));
	CRect rtClient;
	GetClientRect(&rtClient);
	dc.FillRect(&rtClient,&hbr);
}

void CCaptionPanel::OnSize(UINT nType, int cx, int cy)
{
	CPanel::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	CRect rtClient;
	GetClientRect(&rtClient);
	if(m_leftCaption.m_hWnd != NULL)
	{
		m_leftCaption.MoveWindow(CRect(0, 0, rtClient.Width() - 290, rtClient.Height()));
	}
	if(m_centerCaption.m_hWnd != NULL)
	{
		m_centerCaption.MoveWindow(CRect(rtClient.Width() - 290, 0, rtClient.Width() - 100, rtClient.Height()));
	}
	if(m_RightCaption.m_hWnd != NULL)
	{
		m_RightCaption.MoveWindow(CRect(rtClient.Width() - 100, 0, rtClient.Width(), rtClient.Height()));
	}

}
