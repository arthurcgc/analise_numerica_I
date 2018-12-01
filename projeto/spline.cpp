#include "spline.h"
#include "matriz.h"
#include "thomas.h"
#include <iostream>

using namespace std;

/* Auxiliary static funtions */
static void printv(vector<double> v);

static void R_L(vector<double> x, vector<double> mi, vector<double> lamb,
                vector<double> D, vector<double> &R, vector<double> &L);

static void LineInterpolation(double t,double p0x,double p0y,double p1x,double p1y,
                                double *pxt,double *pyt);

/* Open Spline Methods */

void OpenSpline::getGamma()
{
    int n = h.size();
    
    for(int i=0; i < n-1; i++)
        gamma.push_back( ( 2*(h[i]+h[i+1]) )/( v[i]*h[i]*h[i+1] + 2*(h[i]+h[i+1]) ) );
}


void OpenSpline::getLambda()
{
    int n = h.size();

    lambda.push_back(1);
    for(int i=1;i < n-2;i++)
        lambda.push_back( (h[i-1] + h[i]) / (h[i-1] + h[i] + h[i+1]) );
    
    lambda.push_back(1);
}

void OpenSpline::getLambda(vector<double> Gamma)
{
    int n = h.size();

    lambda.push_back(1);
    for(int i=1;i < n-2;i++)
        lambda.push_back( ( Gamma[i-1]*(h[i-1] + h[i]) ) / (Gamma[i-1]*h[i-1] + h[i] + Gamma[i]*h[i+1]) );
    
    lambda.push_back(1);
}


void OpenSpline::getMi()
{
    int n = h.size();
    
    mi.push_back(0);
    for(int i=1;i < n-2;i++)
        mi.push_back( h[i] / (h[i] + h[i+1] + h[i+2]) );
    
    mi.push_back(0);
}

void OpenSpline::getMi(vector<double> Gamma)
{
    int n = h.size();
    
    mi.push_back(0);
    for(int i=1;i < n-2;i++)
        mi.push_back( Gamma[i]*h[i] / (Gamma[i]*h[i] + h[i+1] + Gamma[i+1]*h[i+2]) );
    
    mi.push_back(0);
}


void OpenSpline::getDelta()
{
    int n = h.size();

    for(int i = 0; i < n-1; i++)
        delta.push_back( h[i]/(h[i]+h[i+1]) );
    
}


void OpenSpline::getA_B_C()
{
    for(int i = 0; i < Px.size() ;i++)
    {
        a.push_back( (1-delta[i]) * (1-lambda[i]));
        b.push_back( ((1-delta[i])*lambda[i]) + (delta[i]*(1-mi[i])) );
        c.push_back( delta[i]*mi[i] );
    }
}


void OpenSpline::getM()
{
    int n = Px.size();
    M = matcria(n, n);

    for(int i = 0;i < n;i++)
    {
        if(i>0)
            M[i][i-1] = a[i];
        M[i][i] = b[i];
        if(i+1<n)
            M[i][i+1] = c[i];
    }
}


void OpenSpline::getD()
{
    Dx = Thomas(M, Px);
    Dy = Thomas(M, Py);
}


void OpenSpline::getR_L()
{
    R_L(Px, mi, lambda, Dx, Rx, Lx);
    R_L(Py, mi, lambda, Dy, Ry, Ly);
}


void OpenSpline::DeCasteljau(double b0x,double b0y,	// De Casteljau Algorithm
                            double b1x,double b1y,
                            double b2x,double b2y,
                            double b3x,double b3y,double t_size)
{
    for (double t=0; t<=1.0; t+=t_size)
    {
        double b01x,b01y;	// Primeiro nível de interpolaćões
        LineInterpolation(t,b0x,b0y,b1x,b1y,&b01x,&b01y);
        double b12x,b12y;
        LineInterpolation(t,b1x,b1y,b2x,b2y,&b12x,&b12y);
        double b23x,b23y;
        LineInterpolation(t,b2x,b2y,b3x,b3y,&b23x,&b23y);

        double b012x,b012y;	// Segundo nível de interpolaćões
        LineInterpolation(t,b01x,b01y,b12x,b12y,&b012x,&b012y);
        double b123x,b123y;
        LineInterpolation(t,b12x,b12y,b23x,b23y,&b123x,&b123y);

        double b0123x,b0123y;
        LineInterpolation(t,b012x,b012y,b123x,b123y,&b0123x,&b0123y);

        points_x.push_back(b0123x);
        points_y.push_back(b0123y);
    }
}


void OpenSpline::CalculateSplinePoints(double t_size)
{
    for (int i = 0; i < Px.size()-1; i++)
        DeCasteljau(Px[i],Py[i],Rx[i],Ry[i],Lx[i],Ly[i],Px[i+1],Py[i+1], t_size);
}


void OpenSpline::InitializeVectors(double t_size)
{
    getLambda();
    getMi();
    getDelta();
    getA_B_C();
    getM();
    getD();
    getR_L();

    cout << "printing h:" << endl;
    printv(h);
    cout << "printing lambda:" << endl;
    printv(lambda);
    cout << "printing Mi:" << endl;
    printv(mi);
    cout << "printing delta:" << endl;
    printv(delta);
    cout << "printing M:" << endl;
    printmat(Px.size(), Px.size(), M);
    cout << "printing Dx:" << endl;
    printv(Dx);
    cout << "printing Dy:" << endl;
    printv(Dy);
    cout << "printing Lx:" << endl;
    printv(Rx);
    cout << "printing Ry:" << endl;
    printv(Ry);
    cout << "printing Lx:" << endl;
    printv(Lx);
    cout << "printing Ly:" << endl;
    printv(Ly);

    CalculateSplinePoints(t_size);

    cout << "\n\n";
    for(int i = 0; i < points_x.size(); i++)
        fprintf(stdout,"%.3f\t%.3f\n",points_x[i],points_y[i]);
    cout << "\n\n";
}

void OpenSpline::InitializeVectors(double t_size, vector<double> v)
{
    this->v = v;
    getGamma();
    getLambda(gamma);
    getMi(gamma);
    getDelta();
    getA_B_C();
    getM();
    getD();
    getR_L();


    cout << "printing v:" << endl;
    printv(this->v);
    cout << "printing gamma:" << endl;
    printv(gamma);
    cout << "printing h:" << endl;
    printv(h);
    cout << "printing lambda:" << endl;
    printv(lambda);
    cout << "printing Mi:" << endl;
    printv(mi);
    cout << "printing delta:" << endl;
    printv(delta);
    cout << "printing M:" << endl;
    printmat(Px.size(), Px.size(), M);
    cout << "printing Dx:" << endl;
    printv(Dx);
    cout << "printing Dy:" << endl;
    printv(Dy);
    cout << "printing Lx:" << endl;
    printv(Rx);
    cout << "printing Ry:" << endl;
    printv(Ry);
    cout << "printing Lx:" << endl;
    printv(Lx);
    cout << "printing Ly:" << endl;
    printv(Ly);

    CalculateSplinePoints(t_size);

    cout << "\n\n";
    for(int i = 0; i < points_x.size(); i++)
        fprintf(stdout,"%.3f\t%.3f\n",points_x[i],points_y[i]);
    cout << "\n\n";
}

/* BSpline Methods */
BSpline::BSpline(vector<pair<double,double> > points, double t_size)
{
    //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size);
}

BSpline::BSpline(vector<pair<double,double> > points, double t_size, vector<double> v)
{
    //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size, v);
}

void BSpline::getH()
{
    h.push_back(0);

    for(int i = 1; i < Px.size(); i++)
        h.push_back(1);

    h.push_back(0);
}

/* Dynamic Spline methods */
DynamicSpline::DynamicSpline(vector<pair<double,double> > points, double t_size)
{
        //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size);

}


DynamicSpline::DynamicSpline(vector<pair<double,double> > points, double t_size, vector<double> v)
{
        //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size, v);

}

void DynamicSpline::getH()
{
    int n = Px.size();

    h.push_back(0);

    for(int i = 1; i < n; i++)
        h.push_back(sqrt(pow(Px[i]-Px[i-1],2) + pow(Py[i]-Py[i-1],2)));

    h.push_back(0);
}

/* Auxiliary Static Functions */
static void printv(vector<double> v)
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << '\t';
    cout << endl;
}

static void LineInterpolation(double t,double p0x,double p0y,double p1x,double p1y,
                                       double *pxt,double *pyt)
{
   *pxt=(1.0-t)*p0x+t*p1x;
   *pyt=(1.0-t)*p0y+t*p1y;
}

static void R_L(vector<double> x, vector<double> mi, vector<double> lamb,vector<double> D,
                 vector<double> &R, vector<double> &L)
{
    for(int i = 0; i < D.size(); i++)
    {
        R.push_back( ((1-mi[i])*D[i]) + (mi[i]*D[i+1]) );
        L.push_back( ((1-lamb[i+1])*D[i]) + (lamb[i+1]*D[i+1]) );
    }
}