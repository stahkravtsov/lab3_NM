#include <iostream>
using namespace std;

double** NewM(int n)
{
		double** M1 = (double**) operator new(sizeof(double*) * (n));
		for (int i = 0; i < n; i++)
		{
				M1[i] = (double*) operator new(sizeof(double) * (n));
		}
		return M1;
}

void FreeM(double** M1, int n)
{
		for (int j = 0; j < n; j++)
		{
				delete M1[j];
		}
		delete M1;
}

void PrintM(double** M, int n)
{
		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
						cout << M[i][j] << " ";
				}
				cout << endl;
		}
}

double** FillStartM(void)
{
		double** M1 = NewM(4);

		double M[4][4] = {
				{0.97, 0.31, -0.18, 0.22},
				{-0.21, 2.18, -0.33, 0.22},
				{0.32, -0.18, 0.85, -0.19},
				{0.12, 0.28, -0.14, 2.29}
		};

		for (int j = 0; j < 4; j++)
		{
				for (int r = 0; r < 4; r++)
				{
						M1[j][r] = M[j][r];
				}
		}
		return M1;
}

//double** FillStartM(void)
//{
//		double** M1 = NewM(3);
//
//		double M[3][3] = {
//				{1, 3, -2},
//				{8, 5, 4},
//				{-1, 1, 3}
//		};
//
//		for (int j = 0; j < 3; j++)
//		{
//				for (int r = 0; r < 3; r++)
//				{
//						M1[j][r] = M[j][r];
//				}
//		}
//		return M1;
//}

double DetM(double** M, int n)
{
		if (n == 1)
		{
				return (M[0][0]);
		}
		double res = 0;
		for (int i = 0; i < n; i++)
		{
				double pow = 1;
				if (i % 2 == 1) pow = -1;
				int k = 0, p = 0;

				double** M1 = NewM(n - 1);
				for (int j = 0; j < n; j++)
				{
						for (int r = 0; r < n; r++)
						{
								if (j != 0 && r != i)
								{
										M1[k][p] = M[j][r];
										p++;
								}
						}
						if (p == (n - 1))
						{
								p = 0;
								k++;
						}
				}
				res += pow * M[0][i] * DetM(M1, n - 1);

				FreeM(M1, n - 1);
		}
		return res;
}

double SwapAndFindDetM(double** M, double b[], int n, int f)
{
		double** M1 = NewM(n);

		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
						if (j != f)
						{
								M1[i][j] = M[i][j];
						}
						else
						{
								M1[i][j] = b[i];
						}
				}
		}

		cout << endl << "Matrix with swapped " << f + 1 << " colon" << endl;
		PrintM(M1, n);
		cout << endl;

		double res = DetM(M1, n);
	//	cout << "Det " << res << endl;
		FreeM(M1, n);
		return res;
}

double** ArithmeticAdditionsM(double** M, int n)
{
		double** M1 = NewM(n);
		double add = (1 / DetM(M, n));

		for (int i = 0; i < n; i++)
		{
				for (int j = 0; j < n; j++)
				{
						double** M2 = NewM(n - 1);
						double pow = 1;
						if ((i + j) % 2 == 1) pow = -1;
						int p = 0, k = 0;
						for (int i1 = 0; i1 < n; i1++)
						{
								for (int j1 = 0; j1 < n; j1++)
								{
										if (i != i1 && j != j1)
										{
												M2[k][p] = M[i1][j1];
												p++;
										}
										if (p == n - 1)
										{
												k++;
												p = 0;
										}
								}
						}
						//PrintM(M2, n-1);
						M1[j][i] = pow * DetM(M2, n - 1) * add;
						FreeM(M2, n - 1);
				}
		}
		return M1;
}

double MultiplicationM(double** M, double b[], int n, int pos)
{
		double res = 0;
		for (int i = 0; i < n; i++)
		{
				res += (M[pos][i] * b[i]);
		}
		return res;
}

//END