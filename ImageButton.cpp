// ImageButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Broswer.h"
#include "ImageButton.h"
#include ".\imagebutton.h"


// CImageButton

IMPLEMENT_DYNAMIC(CImageButton, CWnd)
CImageButton::CImageButton()
{
	m_bHover = FALSE;
	m_bButtonDown = FALSE;
}

CImageButton::~CImageButton()
{
}


BEGIN_MESSAGE_MAP(CImageButton, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CImageButton ��Ϣ�������

BOOL CImageButton::Create(const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CWnd::Create(NULL,"",WS_CHILD | WS_VISIBLE,rect,pParentWnd,nID);
}
void CImageButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACKMOUSEEVENT tme = {0};
	tme.cbSize = sizeof(TRACKMOUSEEVENT);
	tme.dwFlags = TME_HOVER | TME_LEAVE;
	tme.dwHoverTime = 1;
	tme.hwndTrack = m_hWnd;
	TrackMouseEvent(&tme);
	CWnd::OnMouseMove(nFlags, point);
}

void CImageButton::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnPaint()
	CRect rectClient;
	GetClientRect(rectClient);
	CDC memDC;
	memDC.CreateCompatibleDC(NULL);
	if (m_bitmap.m_hObject == NULL)
	{
		return;
	}
	memDC.SelectObject(&m_bitmap);
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);
	BOOL bIsEnabled = IsWindowEnabled();
	if (!bIsEnabled)
	{
		dc.StretchBlt(0, 0, rectClient.Width(), rectClient.Height(),
			&memDC, bm.bmWidth * 3 / 4, 0, bm.bmWidth / 4, bm.bmHeight, SRCCOPY);
	}
	if (m_bHover)
	{
		if (m_bButtonDown)
		{
			dc.StretchBlt(0, 0, rectClient.Width(), rectClient.Height(),
				&memDC, bm.bmWidth * 2 / 4, 0, bm.bmWidth / 4, bm.bmHeight, SRCCOPY);
		}
		else
		{
			dc.StretchBlt(0, 0, rectClient.Width(), rectClient.Height(),
				&memDC, bm.bmWidth / 4, 0, bm.bmWidth / 4, bm.bmHeight, SRCCOPY);
		}
		
	}
	else
	{
		dc.StretchBlt(0, 0, rectClient.Width(), rectClient.Height(),
			&memDC, 0, 0, bm.bmWidth / 4, bm.bmHeight, SRCCOPY);
	}
	
}

LRESULT CImageButton::OnMouseHover(WPARAM, LPARAM)
{
	if (!m_bHover)
	{
		m_bHover = TRUE;
		Invalidate();
	}
	return 0;
}
LRESULT CImageButton::OnMouseLeave(WPARAM, LPARAM)
{
	if (m_bHover)
	{
		m_bHover = FALSE;
		Invalidate();
	}
	return 0;
}

int CImageButton::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	return 0;
}

void CImageButton::SetBitmap(UINT nIds)
{
	if (NULL != m_bitmap.m_hObject)
	{
		m_bitmap.DeleteObject();
		
	}
	m_bitmap.LoadBitmap(nIds);
	Invalidate();
}

void CImageButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CWnd::OnLButtonDown(nFlags, point);
	if (!m_bButtonDown)
	{
		m_bButtonDown = TRUE;
		Invalidate();
	}
}

void CImageButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CWnd::OnLButtonUp(nFlags, point);
	if (m_bButtonDown)
	{
		m_bButtonDown = FALSE;
		Invalidate();
		UINT ctrId = ::GetDlgCtrlID(m_hWnd);
		GetParent()->SendMessage(WM_COMMAND,MAKEWPARAM(ctrId, BN_CLICKED), (LPARAM)m_hWnd);
		
	}
	
}
