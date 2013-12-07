#pragma once
#include <atlimage.h>

// CAddressComboBox

class CAddressComboBox : public CComboBox
{
	DECLARE_DYNAMIC(CAddressComboBox)

public:
	CAddressComboBox();
	virtual ~CAddressComboBox();

protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseHover(WPARAM, LPARAM);
	afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	virtual void MeasureItem(LPMEASUREITEMSTRUCT /*lpMeasureItemStruct*/);
public:
	int AddString(LPCTSTR lpszString, HICON);
private:
	CImage m_imgComboLeft;
	CImage m_imgComboRight;
	CImage m_imgComboThumb;
	BOOL m_bThumbHover;
	BOOL m_bButtonDown;
	COMBOBOXINFO m_cbi;
	int m_preItemIndex;
	// 记录鼠标落在当前下拉列表项目的索引
	int m_curItemIndex;

protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnCbnSelchange();
};


