#include "spline.h"

Spline::Spline(vector<pair<double, double> > points)
{
    this->points = points;
    
    this->b.push_back(points[0]);
    for(size_t i = 1; i < 3; i++)
    {
        this->b.push_back(make_pair(0,0));
    }
    int last = points.size() - 1;

    this->b.push_back(points[last]);

}

void getBSpline(double a, double b, double c)
{

}

double getDelta(int index, vector<int> h)
{
    double delta = h[index] / (h[index] + h[index+1]);

    return delta;
}

double getGamma(int index, vector<int> h)
{
    double N = 2 * (h[index] + h[index + 1]);
    double D = ( 2 * ( h[index] + h[index + 1] ) );

    return N/D;
}

double getGamma(int index, vector<int> h, vector<double> v)
{
    double N = 2 * (h[index] + h[index + 1]);
    double D = ( v[index] * h[index] * h[index+1] ) + ( 2 * ( h[index] + h[index + 1] ) );
    
    return N/D;
}

double getLamb(int index, vector<double> gamma, vector<int> h)
{
    double N = (gamma[index-1] * h[index-1]) + h[index];

    double D = (gamma[index-1] * h[index-1]) + (h[index]) + (gamma[index] * h[index+1]);

    return N/D;
}

double getMi(int index, vector<double> gamma, vector<double> h)
{
    double N = gamma[index] * h[index];

    double D = ( gamma[index] * h[index] ) + ( h[index+1] ) + ( gamma[index+1] + h[index+2] );

    return N/D;
}