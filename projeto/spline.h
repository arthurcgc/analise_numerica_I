#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class OpenSpline
{
    public:
        void DeCasteljau(double b0x,double b0y,	// De Casteljau Algorithm
                       double b1x,double b1y,
                       double b2x,double b2y,
                       double b3x,double b3y, double t_size);
        void CalculateSplinePoints(double t_size);
        void InitializeVectors(double t_size);
        void InitializeVectors(double t_size, vector<double> v);

        vector<double> Rx, Ry, Dx, Dy, Lx, Ly, Px, Py, points_x, points_y;
    protected:
        void getGamma();
        void getA_B_C();
        void getLambda();
        void getLambda(vector<double> Gamma);
        void getMi();
        void getMi(vector<double> Gamma);
        void getM();
        void getD();
        void getR_L();
        void getDelta();
        void getAll();
        vector<double> h, gamma, lambda, delta, mi, a, b, c, v;
        double **M;
};


class BSpline : public OpenSpline
{
    public:
        BSpline(vector<pair<double, double> > points, double t_size);
        BSpline(vector<pair<double,double> > points, double t_size, vector<double> v);
    protected:
        void getH();
};

class DynamicSpline : public OpenSpline
{
    public:
        DynamicSpline(vector<pair<double, double> > points, double t_size);
        DynamicSpline(vector<pair<double,double> > points, double t_size, vector<double> v);
    protected:
        void getH();
};

class ClosedSpline : public OpenSpline
{
    public:
        ClosedSpline(vector<pair<double, double> > points, double t_size);
    protected:
        void getMi();
        void getLambda();
        void getH();
        void InitializeVectors(double t_size);
};