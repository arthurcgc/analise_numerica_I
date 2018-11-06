#include <iostream>
#include <bits/stdc++.h>


using namespace std;

double getDelta(int index, vector<double> h)
{
    double delta = h[index] / (h[index] + h[index+1]);

    return delta;
}

double getGamma(int index, vector<double> h)
{
    return 1;
}

double getGamma(int index, vector<double> h, vector<double> v)
{
    double N = 2 * (h[index] + h[index + 1]);
    double D = ( v[index] * h[index] * h[index+1] ) + ( 2 * ( h[index] + h[index + 1] ) );

    return N/D;
}

double getLamb(int index, vector<double> gamma, vector<double> h)
{
    double N = (gamma[index-1] * h[index-1]) + h[index];

    double D = (gamma[index-1] * h[index-1]) + (h[index]) + (gamma[index-1] * h[index+1]);

    return N/D;
}

double getMi(int index, vector<double> gamma, vector<double> h)
{
    double N = gamma[index-1] * h[index];

    double D = ( gamma[index-1] * h[index] ) + ( h[index+1] ) + ( gamma[index-1+1] + h[index+2] );

    return N/D;
}

double getA(int index, vector<double> delta, vector<double> lamb)
{
    return (1-delta[index-1]) * (1-lamb[index-1]);
}

double getB(int index, vector<double> delta, vector<double> lamb, vector<double> mi)
{
    return (1-delta[index-1]) * lamb[index-1] + delta[index-1]*(1-mi[index-1]);
}

double getC(int index, vector<double> delta, vector<double> mi)
{
    return delta[index-1] * mi[index-1];
}

void print_vec_pairs(vector<pair<double, double> > vec)
{
    for(size_t i = 0; i < vec.size(); i++)
    {
        cout <<"("<<vec[i].first << ", " << vec[i].second << ")" << endl;
    }
}

void create_h(vector<double> *h, int n_pair)
{
    
    for(size_t i = 0; i < n_pair; i++)
    {
        h->push_back(i);
    }
    
}

int main()
{
    vector<pair<double, double> > spline1 = {make_pair(1,1), make_pair(2,2), make_pair(1,1)};
    
    int n = spline1.size();

    vector<double> delta;
    vector<double> gamma;
    vector<double> lamb;
    vector<double> mi;
    vector<double> h;


    vector<double> a;
    vector<double> b;
    vector<double> c;
    create_h(&h, n);
    
    for(size_t i = 1; i < n-1; i++)
    {
        delta.push_back(getDelta(i, h));
        gamma.push_back(getGamma(i, h));
        lamb.push_back(getLamb(i, gamma, h));
        mi.push_back(getMi(i, gamma, h));

        a.push_back(getA(i, delta, lamb));
        b.push_back(getB(i, delta, lamb, mi));
        c.push_back(getC(i, delta, mi));
    }
    
    cout << "Delta is: " << delta[0] << endl;
    cout << "Gamma is: " << gamma[0] << endl;
    cout << "Lambda is: " << lamb[0] << endl;
    cout << "Mi is: " << mi[0] << endl;

    cout << "a is: " << a[0] << endl;
    cout << "b is: " << b[0] << endl;
    cout << "c is: " << b[0] << endl;

    
    return 0;
}
