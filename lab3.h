#ifndef LAB3_H
#define LAB3_H

double DetM(double** M, int n);//��������� �������, ������ �������

void PrintM(double** M, int n);//���� �������

double SwapAndFindDetM(double** M, double b[], int n, int f);//����� � �� ����� �� ���� �����, � ��������� �����������

double** NewM(int n);//��������� ���� �������

void FreeM(double** M1, int n);//��������� ���'�� �� �������

double MultiplicationM(double** M, double b[], int n, int pos);//��������� �������

double** ArithmeticAdditionsM(double** M, int n);//����������� ����������

double** FillStartM(void);//���������� ��������� �������

#endif // !HEADER_H
