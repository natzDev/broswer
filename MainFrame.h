#pragma once
#include<atlimage.h>
#include "CaptionPanel.h"
#include "ToolPanel.h"

// CMainFrame

class CMainFrame : public CWnd
{
	DECLARE_DYNAMIC(CMainFrame)

public:
	CMainFrame();
	virtual ~CMainFrame();

protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	CImage m_Image; 
public:
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg void OnNcPaint();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

private:
	CCaptionPanel m_captionPanel;
	CToolPanel m_toolPanel;
public:
	afx_msg BOOL OnNcActivate(BOOL bActive);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	virtual void PostNcDestroy();
};


