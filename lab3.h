#ifndef LAB3_H
#define LAB3_H

double DetM(double** M, int n);//визначним матриці, шукаємо рекурсією

void PrintM(double** M, int n);//вивід матриці

double SwapAndFindDetM(double** M, double b[], int n, int f);//заміна і го рядка на вільні члени, і образунок детермінанта

double** NewM(int n);//створення нової мтариці

void FreeM(double** M1, int n);//звільнення пам'яті від матриці

double MultiplicationM(double** M, double b[], int n, int pos);//множнення матриць

double** ArithmeticAdditionsM(double** M, int n);//арифметичне доповнення

double** FillStartM(void);//заповнення початкової матриці

#endif // !HEADER_H
