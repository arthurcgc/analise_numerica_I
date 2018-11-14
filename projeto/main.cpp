#include <iostream>
#include <bits/stdc++.h>
#include "matriz.h"

using namespace std;

vector<double> h_uniform(int npoints)
{
    vector<double> h;

    h.push_back(0);

    for(int i = 1; i < npoints; i++)
        h.push_back(1);

    h.push_back(0);

    return h;
}

vector<double> lambda_normal_open(vector<double> h)
{
    vector<double> lamb;
    int n = h.size();

    lamb.push_back(1);
    for(int i=1;i < n-2;i++)
        lamb.push_back( (h[i-1] + h[i]) / (h[i-1] + h[i] + h[i+1]) );
    
    lamb.push_back(1);

    return lamb;
}

vector<double> mi_open(vector<double> h)
{
    int n = h.size();
    vector<double> mi;
    mi.push_back(0);
    for(int i=1;i < n-2;i++)
        mi.push_back( h[i] / (h[i] + h[i+1] + h[i+2]) );
    
    mi.push_back(0);

    return mi;
}

vector<double> getDelta(vector<double> h)
{
    int n = h.size();
    vector<double> delta;

    for(int i = 0; i < n-1; i++)
    {
        delta.push_back( h[i]/(h[i]+h[i+1]) );
    }
    return delta;
}

double **create_matrix(int n, vector<double> a, vector<double> b, vector<double> c)
{
    double **A = matcria(n,n);
    for(int i = 0;i < n;i++)
    {
        if(i>0)
            A[i][i-1] = a[i];
        A[i][i] = b[i];
        if(i+1<n)
            A[i][i+1] = c[i];
    }

    return A;
}

void print_vec(vector<double> v)
{
    int n = v.size();
    
    for(size_t i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    
}

void normal_uniform_open_spline()
{
    vector<pair<double,double> > points;

    points = {make_pair(0,0), make_pair(1,1), make_pair(2,0)};

    int n = points.size();

    vector<double> x,y;

    for(size_t i = 0; i < n; i++)
    {
        x.push_back( points[i].first );
        y.push_back( points[i].second );
    }
    
    cout << "h:" <<endl;
    vector<double> h = h_uniform(n);
    print_vec(h);

    cout << "lambda:" <<endl;
    vector<double> lamb = lambda_normal_open(h);
    print_vec(lamb);

    cout << "mi:" <<endl;
    vector<double> mi = mi_open(h);
    print_vec(mi);

    cout << "delta:" <<endl;
    vector<double> delta = getDelta(h);
    print_vec(delta);

    cout << "\n\n";

    vector<double> a,b,c;
    for(int i = 0; i < n;i++)
    {
        a.push_back( (1-delta[i]) * (1-lamb[i]));
        b.push_back( ((1-delta[i])*lamb[i]) + (delta[i]*(1-mi[i])) );
        c.push_back( delta[i]*mi[i] );
    }

    double **A = create_matrix(n, a, b, c);
    printmat(n, n, A);

}



int main()
{
    normal_uniform_open_spline();
    return 0;
}
