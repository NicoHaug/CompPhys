#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "time.h"
using namespace std;

// Functions used
double *mkVec(int n);
double *mkVecX(int n);
double *algorithmA(int n);
double *algorithmB(int n);
int relativeError();
double sourceFunc(double x);
double exactSol(double x);

//Begin main
int main(int argc, char *argv[])
{
        int n;
        cout << "Enter number of grid points:" << endl;
        cin >> n;

        double *x = mkVecX(n);
        double *v1 = algorithmA(n);
        double *v2 = algorithmB(n);
        relativeError();

        ofstream myfile;
        cout << "Writing data to file..." << endl;
        myfile.open("results.txt");
        for(int i = 0; i < n; i++) {
                myfile << x[i] << " " << v1[i] << " " << v2[i] << " " << endl;
        }
        myfile.close();
        cout << "Data written to file" << endl;

        delete [] x; delete [] v1; delete [] v2;
        cout << "Finished!" << endl;
        return 0;
}
//End main


//Functions
double *mkVec(int n)
{
        double *vec = new double[n];
        return (double *)vec;
}


double *mkVecX(int n)
{
        double *x = mkVec(n);
        for (int i=0; i<n; i++) {
                x[i] = i * 1.0 /( (double) n - 1);
        }
        return (double *)x;
}

double *algorithmA(int n)
{
        double h;
        double temp;
        h = 1.0 /( (double) n - 1);

        double *a = mkVec(n);
        double *b = mkVec(n);
        double *c = mkVec(n);
        double *f = mkVec(n);
        double *v = mkVec(n);

        for(int i = 0; i < n; i++) {
                a[i] = -1.0;
                b[i] = 2.0;
                c[i] = -1.0;
                f[i] = pow(h,2) * sourceFunc(i*h);
        }

        // Boundary & Initial Conditions:
        v[0] = 0.0;
        v[n-1] = 0.0;

        //start clock
        clock_t start, finish;
        start = clock();
        // Forward substitution:
        for (int i=2; i < n-1; i++) {
                temp = a[i-1]/b[i-1];
                b[i] -= temp*c[i-1];
                f[i] -= temp*f[i-1];
        }
        // Backward substitution:
        for (int i=n-2; i > 0; i--) {
                v[i] = (f[i] - c[i]*v[i+1])/b[i];
        }
        //stop clock
        finish = clock();
        double timeused = (double) (finish - start)/(CLOCKS_PER_SEC);
        cout << setprecision(10) << setw(20) <<"Algo A elapsed time: " <<
                timeused << endl;

        delete [] a; delete [] b; delete [] c; delete [] f;
        return (double *) v;
}


double *algorithmB(int n)
{
        double h;
        double temp;
        h = 1.0 /( (double) n - 1);

        double *b = mkVec(n);
        double *f = mkVec(n);
        double *v = mkVec(n);

        for(int i = 0; i < n; i++) {
                b[i] = 2.0;
                f[i] = pow(h,2) * sourceFunc(i*h);
        }

        // Boundary & Initial Conditions:
        v[0] = 0.0;
        v[n-1] = 0.0;

        //start clock
        clock_t start, finish;
        start = clock();
        // Forward substitution:
        for (int i=2; i < n-1; i++) {
                b[i] -= 1.0/b[i-1];
                f[i] += f[i-1]/b[i-1];
        }
        // Backward substitution:
        for (int i=n-2; i > 0; i--) {
                v[i] = (f[i] + v[i+1])/b[i];
        }
        //stop clock
        finish = clock();
        double timeused = (double) (finish - start)/(CLOCKS_PER_SEC );
        cout << setprecision(10) << setw(20) <<"Algo B elapsed time: " <<
                timeused << endl;

        delete [] b; delete [] f;
        return (double *) v;
}


int relativeError()
{
        int k = 7;
        double *eps = mkVec(k);
        double *h = mkVec(k);

        for (int j=1; j < k+1; j++ ) {
                int n = pow(10, j);
                cout << n << endl;
                vector<double> epsilon(n);
                double *v = algorithmB(n);
                double *x = mkVecX(n);

                double max_eps = log10(abs((v[1]-exactSol(x[1]))/exactSol(x[1])));
                for (int i=2; i<n-1; i++) {
                        epsilon[i] = log10(abs((v[i]-exactSol(x[i]))/exactSol(x[i])));
                        if (epsilon[i] > max_eps)
                                max_eps = epsilon[i];
                }


                h[j-1] = 1/((double) n-1);
                eps[j-1] = max_eps;

                delete [] v; delete [] x;
        }
        ofstream myfile;
        myfile.open("RelErr.txt");
        for(int j = 0; j < k; j++) {
                myfile << h[j] << " " << eps[j] << endl;
                //cout << eps[j] << endl;
        }
        myfile.close();
        return 0;
}


double sourceFunc(double x)
{
        return 100*exp(-10*x);
}

double exactSol(double x)
{
        return 1.0-(1-exp(-10))*x-exp(-10*x);
}
