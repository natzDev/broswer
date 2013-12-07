// MainFram.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Frame.h"
#include "MainFrame.h"
#include ".\mainframe.h"
/*#include ".\mainfram.h"*/


// CMainFrame
#define CAPTION_HEIGHT 25
#define WND_BORDER_SIZE 4

IMPLEMENT_DYNAMIC(CMainFrame, CWnd)

CMainFrame::CMainFrame()
{
	m_captionPanel.m_hWnd = NULL;
	m_toolPanel.m_hWnd = NULL;
}

CMainFrame::~CMainFrame()
{
}


BEGIN_MESSAGE_MAP(CMainFrame, CWnd)
	ON_WM_GETMINMAXINFO()
	ON_WM_NCCALCSIZE()
	ON_WM_NCPAINT()
	ON_WM_CREATE()
	ON_WM_NCACTIVATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CMainFrame ��Ϣ�������



BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ����ר�ô����/����û���
	HINSTANCE hist = AfxGetInstanceHandle();
	
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	if (GetClassInfoEx(hist,cs.lpszClass,&wcex))
	{
		return TRUE;
	}

	wcex.cbClsExtra = 0;
	wcex.cbSize = sizeof(wcex);
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(NULL,IDC_ARROW);
	wcex.hIcon = LoadIcon(hist,MAKEINTRESOURCE(IDR_MAINFRAME));
	wcex.hIconSm = LoadIcon(hist,MAKEINTRESOURCE(IDR_MAINFRAME));
	wcex.hInstance = hist;
	wcex.lpfnWndProc = AfxWndProc;
	wcex.lpszClassName = cs.lpszClass;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS;

	if (!RegisterClassEx(&wcex))
	{
		return FALSE;
	}
	
	return  TRUE;
}

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	lpMMI->ptMaxPosition.x = 0;
	lpMMI->ptMaxPosition.y = 0;

	lpMMI->ptMinTrackSize.x = 700;
	lpMMI->ptMinTrackSize.y = 700 * 0.618;

	CRect rtWork;

	SystemParametersInfo(SPI_GETWORKAREA,0,&rtWork,0);

	lpMMI->ptMaxTrackSize.x = rtWork.Width();
	lpMMI->ptMaxTrackSize.y = rtWork.Height();

	CWnd::OnGetMinMaxInfo(lpMMI);
}

void CMainFrame::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	int nCxBorder = GetSystemMetrics(SM_CXSIZEFRAME);
	int nCyBorder = GetSystemMetrics(SM_CYSIZEFRAME);

	//�߿���0
	lpncsp->rgrc[0].left -= nCxBorder;
	lpncsp->rgrc[0].right += nCxBorder;
	lpncsp->rgrc[0].top -= nCyBorder;
	lpncsp->rgrc[0].bottom += nCyBorder;

	lpncsp->rgrc[0].left += WND_BORDER_SIZE;
	lpncsp->rgrc[0].right -= WND_BORDER_SIZE;
	lpncsp->rgrc[0].top += WND_BORDER_SIZE;
	lpncsp->rgrc[0].bottom -= WND_BORDER_SIZE;

	CWnd::OnNcCalcSize(bCalcValidRects, lpncsp);
}

//�ǿͻ������Ի�
void CMainFrame::OnNcPaint()
{
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CWnd::OnNcPaint()

	CRect rtWnd;
	GetWindowRect(&rtWnd);

	CDC *pWndDc = GetWindowDC();

	//������߱߿�
	m_Image.Draw(pWndDc->m_hDC,0,0,WND_BORDER_SIZE,rtWnd.Height());
	
	//�����ϱ߱߿�
	m_Image.Draw(pWndDc->m_hDC,0,0,rtWnd.Width(),WND_BORDER_SIZE);

	//�����ұ߱߿�
	m_Image.Draw(pWndDc->m_hDC,rtWnd.Width() - WND_BORDER_SIZE,0,WND_BORDER_SIZE,rtWnd.Height());

	//�����±߱߿�
	m_Image.Draw(pWndDc->m_hDC,0,rtWnd.Height() - WND_BORDER_SIZE,rtWnd.Width(),WND_BORDER_SIZE);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	HINSTANCE hist = AfxGetInstanceHandle();
	ASSERT(hist != NULL);
	m_Image.LoadFromResource(hist,IDB_BORDER);
	ASSERT(m_Image);

	CRect rt;
	GetClientRect(&rt);
	rt.bottom = rt.top + 27;
	if (m_captionPanel.m_hWnd == NULL)
	{
		m_captionPanel.Create(_T("Caption"),WS_CHILD|WS_VISIBLE,rt,this,10005);
	}
	if (m_toolPanel.m_hWnd)
	{
		return 0;
	}
	else
	{
		m_toolPanel.Create(_T("ToolPanel"), WS_CHILD | WS_VISIBLE, CRect(0, 27, rt.right, 78), this, 10006);
	}

	HINSTANCE hInst = LoadLibrary(_T("UxTheme.dll"));
	if (hInst)
	{
		typedef HRESULT (WINAPI *PFUN_SetWindowTheme)(HWND, LPCTSTR, LPCTSTR);
		PFUN_SetWindowTheme pFun = (PFUN_SetWindowTheme)GetProcAddress(hInst, "SetWindowTheme");
		if (pFun)
		{
			pFun(m_hWnd, _T(""), _T("")); //ȥ��xp����
		}
		FreeLibrary(hInst);
	}

	hInst = LoadLibrary(_T("dwmapi.dll"));
	if (hInst)
	{
		typedef HRESULT (WINAPI * TmpFun)(HWND,DWORD,LPCVOID,DWORD);
		TmpFun DwmSetWindowAttributeEX = (TmpFun)::GetProcAddress(hInst, "DwmSetWindowAttribute");
		if (DwmSetWindowAttributeEX)
		{
			DWORD dwAttr = 1;
			DwmSetWindowAttributeEX(GetSafeHwnd(), 2, &dwAttr, 4); //ȥ��vista��Ч
		}
		FreeLibrary(hInst);
	}

	return 0;
}

BOOL CMainFrame::OnNcActivate(BOOL bActive)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SendMessage(WM_NCPAINT);
	return TRUE;
	//return CWnd::OnNcActivate(bActive);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_captionPanel.m_hWnd == NULL) return;
	if (m_toolPanel.m_hWnd == NULL) return;
	CRect rect;
	GetClientRect(rect);
	CRect rectCaptionPanel = rect;
	CRect rectToolPanel = rect;

	rectCaptionPanel.bottom = 27;
	rectToolPanel.top = 27;
	rectToolPanel.bottom = 78;
	m_captionPanel.MoveWindow(&rectCaptionPanel);
	m_toolPanel.MoveWindow(&rectToolPanel);

}

void CMainFrame::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	delete this;
	CWnd::PostNcDestroy();
}
