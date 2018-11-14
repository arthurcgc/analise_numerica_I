#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>
#include "matriz.h"
#include "thomas.h"

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
        cout << v[i] << '\t';
    }
    cout << endl;
    
}

void R_L(vector<double> x, vector<double> mi, vector<double> lamb,vector<double> D, vector<double> &R, vector<double> &L)
{
    
    for(int i = 0; i < D.size(); i++)
    {
        R.push_back( ((1-mi[i])*D[i]) + (mi[i]*D[i+1]) );
        L.push_back( ((1-lamb[i+1])*D[i]) + (lamb[i+1]*D[i+1]) );
    }
    
}

vector<pair<double,double> > points;
int n ;
vector<double> x,y;
vector<double> Dx;
vector<double> Dy;
vector<double> Rx,Lx,Ry,Ly;
vector<double> Px, Py;

void normal_uniform_open_spline()
{
    points = {make_pair(0.5,0.5), make_pair(2,1), make_pair(3,0)};
    n = points.size();
    //definindo os pontos da spline
     for(size_t i = 0; i < n; i++)
    {
        x.push_back( points[i].first );
        y.push_back( points[i].second );
    }

    // obtendo os vetores h, delta, mi, lambda
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

    //obtendo os vetores a, b, c
    vector<double> a,b,c;
    for(int i = 0; i < n;i++)
    {
        a.push_back( (1-delta[i]) * (1-lamb[i]));
        b.push_back( ((1-delta[i])*lamb[i]) + (delta[i]*(1-mi[i])) );
        c.push_back( delta[i]*mi[i] );
    }

    //criando a matriz tridiagonal
    double **A = create_matrix(n, a, b, c);
    printmat(n, n, A);

    //obtendo os vetores dos pontos de controle Dx e Dy
    Dx = Thomas(A, x);
    Dy = Thomas(A, y);
    cout << "vetor Dx:" << endl;
    print_vec(Dx);
    cout << "vetor Dy:" << endl;
    print_vec(Dy);

    // obtendo os vetores R[x,y] e L[x,y]
    R_L(x, mi, lamb, Dx, Rx, Lx);
    R_L(y, mi, lamb, Dy, Ry, Ly);
    cout << "vetor Rx:" << endl;
    print_vec(Rx);
    cout << "vetor Lx:" << endl;
    print_vec(Lx);

    cout << "vetor Ry:" << endl;
    print_vec(Ry);
    cout << "vetor Ly:" << endl;
    print_vec(Ly);
    
}

static void Redraw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    
    for(int i = 0; i < x.size(); i++)
    {
        glVertex2d(x[i],y[i]);
    }
    glEnd();

    glPointSize(6.0);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);    
    for(int i = 0; i < Dx.size(); i++)
    {
        glVertex2d(Dx[i],Dy[i]);
    }
    glEnd();

    glColor3f(0.3,0.3,1);
    glPointSize(6);
    glBegin(GL_POINTS);
    for(int i = 0; i < Rx.size(); i++)
    {
        glVertex2d(Rx[i],Ry[i]);
        glVertex2d(Lx[i],Ly[i]);
    }
    glEnd();

    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("SplineInterpolation");
    gluOrtho2D(-1,5,-1,5);
    glutDisplayFunc(Redraw);
    normal_uniform_open_spline();
    glutMainLoop();
    return 0;
}
