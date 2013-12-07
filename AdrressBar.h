#pragma once
#include "panel.h"
#include "ImageButton.h"
#include "AddressComboBox.h"

class CAddressBar :
	public CPanel
{
public:
	CAddressBar(void);
	~CAddressBar(void);
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CImage m_imgAddressBar;
	CAddressComboBox m_comboAddress;
	CImageButton m_btnGo;

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};
