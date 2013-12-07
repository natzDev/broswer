#pragma once
#include "panel.h"
#include "ImageButton.h"
class CMainToolBar :
	public CPanel
{
public:
	CMainToolBar(void);
	~CMainToolBar(void);
private:
	CImageButton m_btnBackward;
	CImageButton m_btnForward;
	CImageButton m_btnStop;
	CImageButton m_btnRefresh;
	CImageButton m_btnHome;
	CImageButton m_btnRestore;
	CImageButton m_btnFav;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
