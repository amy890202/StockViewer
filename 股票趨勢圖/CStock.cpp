#include "stdafx.h"
#include "CStock.h"
#include <fstream>
#include <iostream>
using namespace std;



CStock::CStock(char s[])
{
	date = NULL;//先將所有指向空指標
	open = NULL;
	high = NULL;
	low = NULL;
	close = NULL;
	adj = NULL;
	vol = NULL;
	strcpy(symbol, s);
	load();
}

void CStock::load()
{
	char filename[100];
	strcpy(filename,symbol);
	strcat(filename, ".csv");//字串連接
	//怎麼確定讀入的資料有幾行 先讀一次取行數再讀一次拿資料
	ifstream fin(filename);
	fin >> no;
	if (date != NULL)//養成習慣若不適指向空指標就delete掉
		delete[] date;
	date = new int[no];//如果有被用過就先清掉再new
	if (open != NULL)
		delete[] open;
	open = new double[no];
	if (high != NULL)
		delete[] high;
	high =new double[no];
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
	for (int i = 0; i < no; i++)//也可以寫一個operator覆寫>>
	{
		fin >> date[i]>>tmp;
		fin >> open[i]>>tmp;
		fin >> low[i];
		fin >> close[i];
		fin >> adj[i];
		fin >> vol[i];
	}
	fin.close();
}



CStock::~CStock()
{
	if (date != NULL)//養成習慣若不適指向空指標就delete掉
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
