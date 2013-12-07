#pragma once
#include "Panel.h"
#include "LeftCaption.h"
#include "CenterCaption.h"
#include "RightCaption.h"

class CCaptionPanel :
	public CPanel
{
public:
	CCaptionPanel(void);
public:
	~CCaptionPanel(void);

	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	CLeftCaption m_leftCaption;
	CCenterCaption m_centerCaption;
	CRightCaption m_RightCaption;
	afx_msg void OnPaint();
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
