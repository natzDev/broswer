#pragma once
#include "Panel.h"
#include <atlimage.h>

class CLeftCaption :
	public CPanel
{
public:
	CLeftCaption(void);
public:
	~CLeftCaption(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	CImage m_imgLeftCaption;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
