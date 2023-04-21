#include "stdafx.h"
#include "CStock.h"
#include <fstream>
#include <iostream>
using namespace std;


CStock::CStock()
{
	no = 0;
	date = NULL;
	open = NULL;
	high = NULL;
	low = NULL;
	close = NULL;
	adj = NULL;
	vol = NULL;
}


CStock::~CStock()
{
	if (date != NULL)
		delete[] date;
	if (open != NULL)
		delete[] open;
	if (high != NULL)
		delete[] high;
	if (low != NULL)
		delete[] low;
	if (close != NULL)
		delete[] close;
	if (adj != NULL)
		delete[] adj;
	if (vol != NULL)
		delete[] vol;
}

void CStock::load(char filepath[], char s[])
{
	char tmp;
	strcpy_s(symbol, s);
	ifstream fin(filepath);
	fin >> no;
	if (date != NULL)
		delete[] date;
	date = new int[no];
	if (open != NULL)
		delete[] open;
	open = new double[no];
	if (high != NULL)
		delete[] high;
	high = new double[no];
	if (low != NULL)
		delete[] low;
	low = new double[no];
	if (close != NULL)
		delete[] close;
	close = new double[no];
	if (adj != NULL)
		delete[] adj;
	adj = new double[no];
	if (vol != NULL)
		delete[] vol;
	vol = new int[no];
	for (int i = 0; i < no; i++)
	{
		fin >> date[i] >> tmp;
		fin >> open[i] >> tmp;
		fin >> high[i] >> tmp;
		fin >> low[i] >> tmp;
		fin >> close[i] >> tmp;
		fin >> adj[i] >> tmp;
		fin >> vol[i];
	}
	fin.close();

}

void CStock::draw(CDC *pDC,int H,int W,int n)
{
	if (no > 0)
	{
		/*CString str;
		str.Format(_T("[%d,%d,%d] Date : %d   Open : %lf   Close : %lf"), H,W, n, date[n], open[n], close[n]);
		pDC->TextOutW(100, 100, str);*/
		int ymin = 20;
		int ymax = H * 3 / 4;
		int N = W / 10;
		int i;
		double smax = high[n];
		double smin = low[n];
		int x1, x2, x3, y1, y2, y3, y4;
		for (i = 1; i < N; i++)
		{
			if (high[n - i] > smax)
				smax = high[n - i];
			if (low[n - i] < smin)
				smin = low[n - i];
		}
		pDC->MoveTo(0, ymin);
		pDC->LineTo(W, ymin);
		pDC->MoveTo(0, ymax);
		pDC->LineTo(W, ymax);
		for (i = 0; i < N; i++)
		{
			x3 = W - i * 10 - 1;
			x2 = x3 - 3;
			x1 = x2 - 3;
			y1 = (high[n - i] - smax) / (smin - smax)*(ymax - ymin) + ymin;
			y2 = (open[n - i] - smax) / (smin - smax)*(ymax - ymin) + ymin;
			y3 = (close[n - i] - smax) / (smin - smax)*(ymax - ymin) + ymin;
			y4 = (low[n - i] - smax) / (smin - smax)*(ymax - ymin) + ymin;
			pDC->MoveTo(x1, y2);
			pDC->LineTo(x3, y2);
			pDC->LineTo(x3, y3);
			pDC->LineTo(x1, y3);
			pDC->LineTo(x1, y2);
			pDC->MoveTo(x2, y1);
			pDC->LineTo(x2, y4);
		}
	}
}
