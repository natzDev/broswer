#pragma once


// CImageButton

class CImageButton : public CWnd
{
	DECLARE_DYNAMIC(CImageButton)

public:
	CImageButton();
	virtual ~CImageButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(const RECT& rect, CWnd* pParentWnd, UINT nID);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg LRESULT OnMouseHover(WPARAM, LPARAM);
	afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
public:
	void SetBitmap(UINT nIds);
private:
	BOOL m_bHover;
	CBitmap m_bitmap;
	BOOL m_bButtonDown;
};				   


