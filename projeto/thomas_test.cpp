#include <iostream>
#include "thomas.h"
#include "matriz.h"

void test1()
{
    int m, n;
    double ** A;
    m = n = 8;

    A = matcria(m, n);
    A[0][0] = 1;
    for(size_t i = 1; i < m-1; i++)
    {
        for(size_t j = i-1; j <= i + 1; j++)
        {
            A[i][j] = i + j;
        }
    }
    A[n-1][n-1] = 1;

    cout << "Matriz A:\n";
    printmat(m, n, A);

    vector<double> points = {1,2,3,4,5,6,7,8};
    vector<double> D = Thomas(A, points);


    cout << "x points:\n";
    for(size_t i = 0; i < D.size(); i++)
    {
        cout << D[i] << endl;
    }
}


void test2()
{
    int m, n;
    double ** A;
    m = n = 3;

    A = matcria(m, n);
    A[0][0] = 1; A[0][1] = 0;A[0][2] = 0;
    A[1][0] = 0.25;A[1][1] = 0.5;A[1][2] = 0.25;
    A[2][0] = 0; A[2][1] = 0; A[2][2] = 1;

    cout << "Matriz A:\n";
    printmat(m, n, A);

    vector<double> points = {0,1,0};
    vector<double> D = Thomas(A, points);


    cout << "x points:\n";
    for(int i = 0; i < D.size(); i++)
    {
        cout << D[i] << endl;
    }
}

int main()
{
    //test1();
    test2();
    return 0;
}