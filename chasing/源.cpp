#include <iostream>
using namespace std;

void LU_decom(double **a, double *b, const int n);
int main()
{
	int n = 4;
	double **a = NULL, *b = NULL;
	//double temp_a[][3] = { 6,7,5,7,13,8,5,8,6};
	//double temp_b[] = {9,10,9};
	double temp_a[][4] = {
		{2,-1,0,0},
		{-1,2,-1,0},
		{0,-1,2,-1},
		{0,0,-1,2} };
	double temp_b[] = {0,0,0,5};
	b = new double[n];
	a = new double *[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		b[i] = temp_b[i];
		for (int j = 0; j < n; j++)
			a[i][j] = temp_a[i][j];
	}
	//进行lu分解
	LU_decom(a, b, n);
	getchar();
	return 1;
}

void LU_decom(double **a, double *b, const int n)
{
	double *l = new double[n];
	double *r = new double[n];
	double *f = new double[n];
	// 进行LU分解； 
	// l为L的次对角，L的主对角为1
	// r,f 为U的上半角的值
	for (int i = 0; i< n; i++)
	{
		for (int j = i-1; j<=i+1 && j<n ; j++)
		{
			if (j == -1)	
				continue;
			if (j == i+1)
				f[i] = a[i][j];
			else if(j == i)
				if (i == 0)
					r[i] = a[i][i];
				else
					r[i] = a[i][i] - l[i] * f[i - 1];
			else
				l[i] = a[i][j] / r[i - 1];
		
		}
	}

	// x,y 
	double *y = new double[n];
	double *x = new double[n];

	for (int i = 0; i < n ; i++)
		if (i == 0)
			y[i] = b[i];
		else
			y[i] = b[i] - l[i] * y[i - 1];

	for (int i = n-1; i>-1; i--)
		if (i == n -1)
			x[i] = y[i] / r[i];
		else 
			x[i] = (y[i] - f[i] * x[i + 1]) / r[i];

	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;

	delete[] l;
	delete[] r;
	delete[] f;
	delete[] x;
	delete[] y;
}