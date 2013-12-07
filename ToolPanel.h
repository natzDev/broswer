#pragma once
#include <atlimage.h>
#include "panel.h"
#include "MainToolBar.h"
#include "AdrressBar.h"
#define IDC_MAINTOOLBAR 10006
#define IDC_ADDRESSBAR 10007
class CToolPanel :
	public CPanel
{
public:
	CToolPanel(void);
	~CToolPanel(void);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
private:
	CImage m_imgTool;
	CMainToolBar m_wndMainToolBar;
	CAddressBar m_wndAddressBar;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
