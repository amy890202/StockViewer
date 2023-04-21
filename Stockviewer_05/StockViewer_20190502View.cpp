
// StockViewer_20190502View.cpp: CStockViewer20190502View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "StockViewer_20190502.h"
#endif

#include "StockViewer_20190502Doc.h"
#include "StockViewer_20190502View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStockViewer20190502View

IMPLEMENT_DYNCREATE(CStockViewer20190502View, CView)

BEGIN_MESSAGE_MAP(CStockViewer20190502View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Prev, &CStockViewer20190502View::OnPrev)
	ON_COMMAND(ID_Next, &CStockViewer20190502View::OnNext)
	ON_COMMAND(ID_First, &CStockViewer20190502View::OnFirst)
	ON_COMMAND(ID_Last, &CStockViewer20190502View::OnLast)
	ON_UPDATE_COMMAND_UI(ID_Prev, &CStockViewer20190502View::OnUpdatePrev)
	ON_UPDATE_COMMAND_UI(ID_Next, &CStockViewer20190502View::OnUpdateNext)
	ON_UPDATE_COMMAND_UI(ID_First, &CStockViewer20190502View::OnUpdateFirst)
	ON_UPDATE_COMMAND_UI(ID_Last, &CStockViewer20190502View::OnUpdateLast)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CStockViewer20190502View 建構/解構

CStockViewer20190502View::CStockViewer20190502View() noexcept
{
	// TODO: 在此加入建構程式碼
	pt1.x = -1;
}

CStockViewer20190502View::~CStockViewer20190502View()
{
}

BOOL CStockViewer20190502View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CStockViewer20190502View 繪圖

void CStockViewer20190502View::OnDraw(CDC* pDC)
{
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(rect);
	int H = rect.Height();
	int W = rect.Width();
	// TODO: 在此加入原生資料的描繪程式碼
	pDoc->stock.draw(pDC,H,W,pDoc->n);
	if (pt1.x == -1 && pt2.y>=20 && pt2.y<=3*H/4)
	{
		pDC->MoveTo(0, pt2.y);
		pDC->LineTo(W, pt2.y);
		pDC->MoveTo(pt2.x, 20);
		pDC->LineTo(pt2.x, 3*H/4);
	}
}


// CStockViewer20190502View 列印

BOOL CStockViewer20190502View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CStockViewer20190502View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CStockViewer20190502View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// CStockViewer20190502View 診斷

#ifdef _DEBUG
void CStockViewer20190502View::AssertValid() const
{
	CView::AssertValid();
}

void CStockViewer20190502View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStockViewer20190502Doc* CStockViewer20190502View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStockViewer20190502Doc)));
	return (CStockViewer20190502Doc*)m_pDocument;
}
#endif //_DEBUG


// CStockViewer20190502View 訊息處理常式


void CStockViewer20190502View::OnPrev()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->n--;
	Invalidate();
}


void CStockViewer20190502View::OnNext()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->n++;
	Invalidate();
}


void CStockViewer20190502View::OnFirst()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(rect);
	int W = rect.Width();
	pDoc->n = W/10 - 1;
	Invalidate();
}


void CStockViewer20190502View::OnLast()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->n = pDoc->stock.no-1;
	Invalidate();
}


void CStockViewer20190502View::OnUpdatePrev(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(rect);
	int W = rect.Width();
	pCmdUI->Enable(pDoc->n!= W/10-1);
}


void CStockViewer20190502View::OnUpdateNext(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pCmdUI->Enable(pDoc->n != pDoc->stock.no-1);
}


void CStockViewer20190502View::OnUpdateFirst(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(rect);
	int W = rect.Width();
	pCmdUI->Enable(pDoc->n != W / 10 - 1);
}


void CStockViewer20190502View::OnUpdateLast(CCmdUI *pCmdUI)
{
	// TODO: 在此加入您的命令更新 UI 處理常式程式碼
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pCmdUI->Enable(pDoc->n != pDoc->stock.no - 1);
}


void CStockViewer20190502View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	pt1 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CStockViewer20190502View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CStockViewer20190502Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->n -= ((point.x - pt1.x) / 10);
	pt1.x = -1;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CStockViewer20190502View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	if (pt1.x == -1)
	{
		pt2 = point;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
