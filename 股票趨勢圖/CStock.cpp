#include "stdafx.h"
#include "CStock.h"
#include <fstream>
#include <iostream>
using namespace std;



CStock::CStock(char s[])
{
	date = NULL;//���N�Ҧ����V�ū���
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
	strcat(filename, ".csv");//�r��s��
	//���T�wŪ�J����Ʀ��X�� ��Ū�@������ƦAŪ�@�������
	ifstream fin(filename);
	fin >> no;
	if (date != NULL)//�i���ߺD�Y���A���V�ū��дNdelete��
		delete[] date;
	date = new int[no];//�p�G���Q�ιL�N���M���Anew
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
	for (int i = 0; i < no; i++)//�]�i�H�g�@��operator�мg>>
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
	if (date != NULL)//�i���ߺD�Y���A���V�ū��дNdelete��
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
