#include <iostream>
#include "lab3.h"

using namespace std;

int main()
{

		double b[3] = { 1.32, -0.44, 0.64 };
		double** M1 = FillStartM();
		cout << "Start matrix" << endl;
		PrintM(M1, 3);
		cout << endl;

		if (DetM(M1, 3) == 0)
		{
				cout << "There is no answer";
				return 0;
		}

		double x1 = SwapAndFindDetM(M1, b, 3, 0) / DetM(M1, 3);
		double x2 = SwapAndFindDetM(M1, b, 3, 1) / DetM(M1, 3);
		double x3 = SwapAndFindDetM(M1, b, 3, 2) / DetM(M1, 3);

		cout.precision(7);

		cout << "Cramer's method" << endl;
		cout << "X1 = " << x1 << endl;
		cout << "X2 = " << x2 << endl;
		cout << "X3 = " << x3 << endl;

		double** M3 = ArithmeticAdditionsM(M1, 3);
		FreeM(M1, 3);
		cout.precision(4);
		cout<<endl << endl << "ArithmeticAdditions" << endl;
		PrintM(M3, 3);
		cout.precision(7);

		double X1 = MultiplicationM(M3, b, 3, 0);
		double X2 = MultiplicationM(M3, b, 3, 1);
		double X3 = MultiplicationM(M3, b, 3, 2);
		FreeM(M3, 3);

		cout << endl << "The inverse matrix method" << endl;
		cout << "X1 = " << X1 << endl;
		cout << "X2 = " << X2 << endl;
		cout << "X3 = " << X3 << endl;

		return 0;
}