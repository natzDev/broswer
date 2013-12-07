#include "StdAfx.h"
#include ".\adrressbar.h"

#define IDC_COMBO_ADDRESS 10001
#define IDC_BTN_GO 10002
CAddressBar::CAddressBar(void)
{
}

CAddressBar::~CAddressBar(void)
{
}
BEGIN_MESSAGE_MAP(CAddressBar, CPanel)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

int CAddressBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CPanel::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	ASSERT(m_imgAddressBar.IsNull());
	ASSERT(m_comboAddress.m_hWnd == NULL);
	ASSERT(m_btnGo.m_hWnd == NULL);
	m_imgAddressBar.LoadFromResource(AfxGetInstanceHandle(), IDB_TOOLBAR);
	m_comboAddress.Create(WS_VISIBLE | WS_CHILD | WS_VSCROLL | CBS_AUTOHSCROLL 
		| CBS_DROPDOWN | CBS_HASSTRINGS |CBS_OWNERDRAWVARIABLE,
		CRect(20, 11, lpCreateStruct->cx - 31, 200), this, IDC_COMBO_ADDRESS);
	m_comboAddress.SetItemHeight(-1, 22);
	for (int i = 0; i < 10; ++i)
	{
		CString strItem;
		strItem.Format("%d", i);
		HICON hIcon = ::LoadIcon(NULL, IDI_INFORMATION);
		m_comboAddress.AddString(strItem, hIcon);
	}
	m_btnGo.Create(CRect(lpCreateStruct->cx -31, 11, lpCreateStruct->cx, 39), this, IDC_BTN_GO);
	m_btnGo.SetBitmap(IDB_COMBO_GO);
	return 0;
}

void CAddressBar::OnSize(UINT nType, int cx, int cy)
{
	CPanel::OnSize(nType, cx, cy);
	if (m_comboAddress.m_hWnd == NULL) return;
	if (m_btnGo.m_hWnd == NULL) return;
	m_comboAddress.MoveWindow(CRect(20, 11, cx - 31, 200));
	m_btnGo.MoveWindow(CRect(cx -31, 11, cx, 39));
	m_comboAddress.SetItemHeight(-1, 22);//这句不加高度又会变成系统默认24，下边就会没对齐
}

void CAddressBar::OnPaint()
{
	CPaintDC dc(this);
	CRect rectClient;
	GetClientRect(rectClient);
	m_imgAddressBar.Draw(dc.m_hDC, rectClient);
}
