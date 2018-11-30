#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class OpenSpline
{
    public:
        void getA_B_C();
        void getLambda();
        void getMi();
        void getM();
        void getD();
        void getR_L();
        void getDelta();
        void getAll();
        void DeCasteljau(double b0x,double b0y,	// De Casteljau Algorithm
                       double b1x,double b1y,
                       double b2x,double b2y,
                       double b3x,double b3y, double t_size);
        void CalculateSplinePoints(double t_size);
    //protected:
        vector<double> h, gamma, lambda, delta, mi, Rx, 
        Lx, Ry, Ly, Px, Py, Dx, Dy, a, b, c;
        double **M;
        vector<double> points_x,points_y;
};


class BSpline : public OpenSpline
{
    public:
        BSpline(vector<pair<double, double> > points, double t_size);
        void getH();
};

class DynamicSpline : public OpenSpline
{
    public:
        DynamicSpline(vector<pair<double, double> > points, double t_size);
        void getH();
};