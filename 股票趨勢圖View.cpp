
// 股票趨勢圖View.cpp: C股票趨勢圖View 類別的實作
//

#include "stdafx.h"
// SHARED_HANDLERS 可以定義在實作預覽、縮圖和搜尋篩選條件處理常式的
// ATL 專案中，並允許與該專案共用文件程式碼。
#ifndef SHARED_HANDLERS
#include "股票趨勢圖.h"
#endif

#include "股票趨勢圖Doc.h"
#include "股票趨勢圖View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C股票趨勢圖View

IMPLEMENT_DYNCREATE(C股票趨勢圖View, CView)

BEGIN_MESSAGE_MAP(C股票趨勢圖View, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C股票趨勢圖View 建構/解構

C股票趨勢圖View::C股票趨勢圖View() noexcept
{
	// TODO: 在此加入建構程式碼

}

C股票趨勢圖View::~C股票趨勢圖View()
{
}

BOOL C股票趨勢圖View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// C股票趨勢圖View 繪圖

void C股票趨勢圖View::OnDraw(CDC* /*pDC*/)
{
	C股票趨勢圖Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}


// C股票趨勢圖View 列印

BOOL C股票趨勢圖View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void C股票趨勢圖View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void C股票趨勢圖View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// C股票趨勢圖View 診斷

#ifdef _DEBUG
void C股票趨勢圖View::AssertValid() const
{
	CView::AssertValid();
}

void C股票趨勢圖View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C股票趨勢圖Doc* C股票趨勢圖View::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C股票趨勢圖Doc)));
	return (C股票趨勢圖Doc*)m_pDocument;
}
#endif //_DEBUG


// C股票趨勢圖View 訊息處理常式
