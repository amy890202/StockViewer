#pragma once
class CStock
{ 
public:
	CStock(char[]);
	~CStock();
	int no;//��public���j�a�����D�ڦ��X�����
	char symbol[20];
	void load();//Ū��
	double readclose(int n) { return close[n]; };//Ū��n�Ѧ��L��
private:
	int *date;
	double *open;
	double *high;
	double *low;
	double *close;
	double *adj;
	int *vol;


};

