
// 股票趨勢圖.h: 股票趨勢圖 應用程式的主要標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// C股票趨勢圖App:
// 查看 股票趨勢圖.cpp 以了解此類別的實作
//

class C股票趨勢圖App : public CWinApp
{
public:
	C股票趨勢圖App() noexcept;


// 覆寫
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C股票趨勢圖App theApp;
