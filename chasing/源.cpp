#include <iostream>
using namespace std;

int main()
{
	int n = 5;
	double **a = NULL, *b = NULL;
	//double temp_a[][3] = { 6,7,5,7,13,8,5,8,6};
	//double temp_b[] = {9,10,9};
	double temp_a[][5] = {
		{ 2,-2,0,0,-1 },
		{ -2,3,-2,0,0 },
		{ 0,-2,5,-3,0 },
		{ 0,0,-3,10,4 },
		{ -1,0,0,4,10 } };
	double temp_b[] = { -1,-1,0,11,13 };
	b = new double[n];
	a = new double *[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new double[n];
		b[i] = temp_b[i];
		for (int j = 0; j < n; j++)
			a[i][j] = temp_a[i][j];
	}
}

