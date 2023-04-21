#pragma once
class CStock
{ 
public:
	CStock(char[]);
	~CStock();
	int no;//放public讓大家都知道我有幾筆資料
	char symbol[20];
	void load();//讀檔
	double readclose(int n) { return close[n]; };//讀第n天收盤價
private:
	int *date;
	double *open;
	double *high;
	double *low;
	double *close;
	double *adj;
	int *vol;


};

