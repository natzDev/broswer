#pragma once
#include "Panel.h"
#include <atlimage.h>
#include "ImageButton.h"
class CRightCaption :
	public CPanel
{
public:
	CRightCaption(void);
public:
	~CRightCaption(void);
public:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMinButtonClicked();
	afx_msg void OnMaxButtonClicked();
	afx_msg void OnCloseButtonClicked();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CImageButton m_minBtn, m_maxBtn, m_closeBtn;
	CImage m_imgRightCaption;
};
