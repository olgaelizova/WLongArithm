// LongArithm.cpp : Defines the entry point for the console application.
//
// lalalalalalala
#include "stdafx.h"

#include "WNFLInteger.h"

double** obr_matr(double **A, int N);

int _tmain(int argc, _TCHAR* argv[])
{
	WNFLInteger * a = new WNFLInteger(4);

	double d = 0.7;
	/*
	for (int k = 0; k < 1000; k++)
	{
		d /= 7;
		d /= 8;
		d *= 7;
		d *= 8;
	}
	*/

	double** t_matr = new double*[100];

	for (int a = 0; a < 100; a++)
	{
		
		t_matr[a] = new double[100];

		for (int b = 0; b < 100; b++)
		{
			double RRRR = (double)(rand() % 150464684) / 150464684;
			t_matr[a][b] = RRRR;
		}
	}

	obr_matr(t_matr, 100);

	bool ok = false;

	
	
	return 0;
}



double** obr_matr(double **A, int N) // proverit' pravilnost
{
	double temp;

	double **E = new double *[N];

	for (int i = 0; i < N; i++)
		E[i] = new double[N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
		E[i][j] = 0.0;

		if (i == j)
			E[i][j] = 1.0;
		}

	for (int k = 0; k < N; k++)
	{
		temp = A[k][k];

		for (int j = 0; j < N; j++)
		{
			A[k][j] /= temp;
			E[k][j] /= temp;
		}

		for (int i = k + 1; i < N; i++)
		{
			temp = A[i][k];

			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int k = N - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = A[i][k];

			for (int j = 0; j < N; j++)
			{
				A[i][j] -= A[k][j] * temp;
				E[i][j] -= E[k][j] * temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
		A[i][j] = E[i][j];
		//cout << A[i][j] <<endl;
		}

	for (int i = 0; i < N; i++)
		delete[] E[i];

	delete[] E;

	return A;
}

/*
double transp_matr(double matr, int N, int M)  // N=len, M=col
{
double** t_matr = new double*[M];

for(int i=0; i<M; i++)
{
t_matr[i] = new double[N];
for(int j=0; j<N; j++)
{
t_matr[i][j] = matr[j][i];
}
}*/



double matrONmatr(double matr1/*kvadr*/, double** matr2/*pryamoug*/, int N/*len*/, int M/*col*/)
{
	double** mul = new double*[M];

	for (int i = 0; i<M; i++)//stroki
	{
		mul[i] = new double[N];
		for (int j = 0; j<N; j++)//stolbcy
		{
			//mul[0][0] = matr1[0][0]*matr2[0][0] + matr1[0][1]*matr2[1][0];
			for (int t = 0; t<2; t++)
			{
			//	mul[i][j] += matr1[i][t] * matr2[t][j];
			}

		//	cout << mul[i][j] << "\n";
		}
	//	cout << "\n\n";
	}
	return 4;
//	return mul;
}
