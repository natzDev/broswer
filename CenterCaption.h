#pragma once
#include "Panel.h"
#include <atlimage.h>
class CCenterCaption :
	public CPanel
{
public:
	CCenterCaption(void);
public:
	~CCenterCaption(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	CImage m_imgCenterCaption;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
