// AddressComboBox.cpp : 实现文件
//

#include "stdafx.h"
#include "Broswer.h"
#include "AddressComboBox.h"
#include ".\addresscombobox.h"


// CAddressComboBox

IMPLEMENT_DYNAMIC(CAddressComboBox, CComboBox)
CAddressComboBox::CAddressComboBox()
{
}

CAddressComboBox::~CAddressComboBox()
{
}


BEGIN_MESSAGE_MAP(CAddressComboBox, CComboBox)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_WM_CREATE()
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnCbnSelchange)
END_MESSAGE_MAP()



// CAddressComboBox 消息处理程序


void CAddressComboBox::OnPaint()
{
	COMBOBOXINFO cbi;
	cbi.cbSize = sizeof(COMBOBOXINFO);
	GetComboBoxInfo(&cbi);
	m_cbi = cbi;
	CRect rcEdit;
	rcEdit.left =22;
	rcEdit.right = cbi.rcButton.left;
	rcEdit.top = 5;
	rcEdit.bottom =23;
	::MoveWindow(cbi.hwndItem, rcEdit.left,rcEdit.top,rcEdit.Width(),rcEdit.Height(),TRUE);

	CPaintDC dc(this); 
	if (m_imgComboLeft.IsNull()) return;
	if (m_imgComboRight.IsNull()) return;
	CRect rectClient;
	GetClientRect(rectClient);
	m_imgComboLeft.Draw(dc.m_hDC, CRect(0,0,6,28), CRect(0,0,6,28));
	m_imgComboRight.Draw(dc.m_hDC, CRect(6,rectClient.top,rectClient.right ,rectClient.bottom), CRect(0,0,3,28));
	CRect rectThumb = m_cbi.rcButton;
	rectThumb.top = 0;
	rectThumb.bottom = 28;
	if (m_bThumbHover)
	{
		if (m_bButtonDown)
		{
			m_imgComboThumb.Draw(dc.m_hDC, rectThumb,CRect(20,0,40,28));
		}
		else
		{
			m_imgComboThumb.Draw(dc.m_hDC, rectThumb,CRect(40,0,60,28));
		}
	}
	else
	{
		m_imgComboThumb.Draw(dc.m_hDC, rectThumb,CRect(0,0,20,28));
	}
	int nItem = GetCurSel();
	HICON hIcon = (HICON)GetItemData(nItem);
	DrawIconEx(dc.m_hDC,3, 5,hIcon,16,16,0,0,DI_NORMAL);

}

void CAddressComboBox::OnSize(UINT nType, int cx, int cy)
{
	CComboBox::OnSize(nType, cx, cy);
	COMBOBOXINFO cbi;
	cbi.cbSize = sizeof(COMBOBOXINFO);
	GetComboBoxInfo(&cbi);
	m_cbi = cbi;
	CRect rcEdit;
	rcEdit.left =22;
	rcEdit.right = cbi.rcButton.left;
	rcEdit.top = 5;
	rcEdit.bottom =23;
	::MoveWindow(cbi.hwndItem, rcEdit.left,rcEdit.top,rcEdit.Width(),rcEdit.Height(),TRUE);
}

void CAddressComboBox::OnMouseMove(UINT nFlags, CPoint point)
{
	TRACKMOUSEEVENT tme = {0};
	tme.cbSize = sizeof(TRACKMOUSEEVENT);
	tme.dwFlags = TME_HOVER | TME_LEAVE;
	tme.dwHoverTime = 1;
	tme.hwndTrack = m_hWnd;
	TrackMouseEvent(&tme);
	CComboBox::OnMouseMove(nFlags, point);
}

LRESULT CAddressComboBox::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	CPoint point;
	point.x = LOWORD(lParam);
	point.y = HIWORD(lParam);
	CRect rectThumb = m_cbi.rcButton;
	if (!m_bThumbHover)
	{
		
		if (rectThumb.PtInRect(point))
		{
			m_bThumbHover = TRUE;
			if (wParam == MK_LBUTTON)
			{
				m_bButtonDown = TRUE;
			}
			else
			{
				m_bButtonDown = FALSE;
			}
			Invalidate();
		}
		
	}
	return 0;
}
LRESULT CAddressComboBox::OnMouseLeave(WPARAM, LPARAM)
{
	if (m_bThumbHover)
	{
		m_bThumbHover = FALSE;
		Invalidate();
	}
	m_bButtonDown = FALSE;
	return 0;
}

int CAddressComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;
 	ASSERT(m_imgComboLeft.IsNull());
	ASSERT(m_imgComboRight.IsNull());
 	ASSERT(m_imgComboThumb.IsNull());
	m_imgComboLeft.LoadFromResource(AfxGetInstanceHandle(), IDB_COMBO_LEFT);
	m_imgComboRight.LoadFromResource(AfxGetInstanceHandle(), IDB_COMBO_RIGHT);
	m_imgComboThumb.LoadFromResource(AfxGetInstanceHandle(), IDB_COMBO_THUMB);
	return 0;
}

int CAddressComboBox::AddString(LPCTSTR lpszString, HICON hIcon)
{
	int nItem = CComboBox::AddString(lpszString);
	SetItemData(nItem, (DWORD)hIcon);
	return nItem;
}


void CAddressComboBox::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);
	CRect rectItem = lpDrawItemStruct->rcItem;
	HICON hIcon = (HICON)lpDrawItemStruct->itemData;
	dc.SetBkMode(TRANSPARENT);
	if ( lpDrawItemStruct->itemID == m_curItemIndex )
	{
		CBrush brush(RGB(255,0,0));
		dc.FillRect(&lpDrawItemStruct->rcItem, &brush);
	}
	DrawIconEx(lpDrawItemStruct->hDC,rectItem.left, rectItem.top,hIcon,16,16,0,0,DI_NORMAL);
	CString strItem;
	GetLBText(lpDrawItemStruct->itemID, strItem);
	//::DrawText(lpDrawItemStruct->hDC,strItem, -1, CRect(20, rectItem.top, rectItem.right, rectItem.bottom), DT_LEFT | DT_SINGLELINE | DT_WORD_ELLIPSIS);
	dc.DrawText(strItem,CRect(20, rectItem.top, rectItem.right, rectItem.bottom), DT_LEFT | DT_SINGLELINE | DT_WORD_ELLIPSIS);
	dc.Detach();//必须detach，不然会出现鼠标放上去才显示
}

void CAddressComboBox::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = 22;
}

LRESULT CAddressComboBox::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (message == WM_CTLCOLORLISTBOX)
	{
		TRACE("WM_CTLCOLOREDIT");
		HWND hListBox = (HWND)lParam;  
		// 获取下拉列表指针
		CListBox* pListBox = (CListBox*)FromHandle(hListBox);  
		ASSERT(pListBox);  
		// 获取下拉列表中的项目数
		int nCount = pListBox->GetCount();  

		if(CB_ERR != nCount)  
		{          
			// 得到鼠标坐标（相对于屏幕坐标）
			CPoint pt;  
			GetCursorPos(&pt); 
			// 转换客户区坐标
			pListBox->ScreenToClient(&pt);  
			// 遍历下拉列表项目
			CRect rc;  
			for(int i=0; i<nCount; i++)  
			{  
				// 获取下拉列表中指定索引项目的区域
				pListBox->GetItemRect(i, &rc);
				// 判断鼠标位置是否落在下拉列表项目中
				if(rc.PtInRect(pt))  
				{
					// 记录鼠标落在下拉列表项目中前一个项目的索引
					m_preItemIndex = m_curItemIndex;
					// 记录鼠标落在当前下拉列表项目的索引
					m_curItemIndex = i;
					if ( m_preItemIndex != m_curItemIndex )
					{
						// 获取前一个下拉列表项目的矩形
						CRect preRc;
						pListBox->GetItemRect( m_preItemIndex,&preRc );
						pListBox->InvalidateRect( &preRc );
						// 记录鼠标位置当前所在的下拉列表项目
						CRect rcFous( rc );
						if ( rcFous.PtInRect( pt ) )
						{
							pListBox->InvalidateRect( &rc );
						}
						break;  
					}
				}
			}  
		}  
	}  

	
	return CComboBox::WindowProc(message, wParam, lParam);
}

void CAddressComboBox::OnCbnSelchange()
{
	// TODO: 在此添加控件通知处理程序代码
	InvalidateRect(NULL);
}
