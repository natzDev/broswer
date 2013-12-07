#include "StdAfx.h"
#include ".\maintoolbar.h"
#define IDC_BTN_BACKWARD 10007
#define IDC_BTN_FORWARD	10008
#define IDC_BTN_STOP 10009
#define IDC_BTN_REFRESH 10010
#define IDC_BTN_HOME 10011
#define IDC_BTN_RESTORE 10012
#define IDC_BTN_FAV 10013
#include "resource.h"
CMainToolBar::CMainToolBar(void)
{
}

CMainToolBar::~CMainToolBar(void)
{
}
BEGIN_MESSAGE_MAP(CMainToolBar, CPanel)
	ON_WM_CREATE()
END_MESSAGE_MAP()

int CMainToolBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_btnBackward.Create(CRect(0,0,40,51), this, IDC_BTN_BACKWARD);
	m_btnBackward.SetBitmap(IDB_BACKWARD);
	m_btnForward.Create(CRect(40,0,78,51), this, IDC_BTN_FORWARD);
	m_btnForward.SetBitmap(IDB_FORWARD);
	m_btnStop.Create(CRect(78,0,117,51), this, IDC_BTN_STOP);
	m_btnStop.SetBitmap(IDB_STOP);
	m_btnRefresh.Create(CRect(117,0,155,51), this, IDC_BTN_REFRESH);
	m_btnRefresh.SetBitmap(IDB_REFRESH);
	m_btnHome.Create(CRect(155,0,187,51), this, IDC_BTN_HOME);
	m_btnHome.SetBitmap(IDB_HOME);
	m_btnRestore.Create(CRect(187,0,224,51), this, IDC_BTN_RESTORE);
	m_btnRestore.SetBitmap(IDB_RESTORE);
	m_btnFav.Create(CRect(224,0,260,51), this, IDC_BTN_FAV);
	m_btnFav.SetBitmap(IDB_FAV);
	return 0;
}
