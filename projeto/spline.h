#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Spline
{
    public:

        //creates Spline with n interpolating points
        Spline(vector<pair<double, double> > points);

        // calculates the values of a, b and c of a Uniform Spline
        void getBSpline(double a, double b, double c);

        // calulates P(0) or P(1), i determines the Spline number and t determines P(t)
        void getP(int i,bool t);

    private:
        vector<pair<double, double> > points;
        vector<pair<double, double> > b;
        vector<Spline> splines;
        int inx_tram;
};
