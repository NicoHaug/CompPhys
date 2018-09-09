/**
 * Program for solving second-order differential equations on the form
 *                   u''(x) = f(x)
 * by recasting the DE as a tridiagonal matrix equation on the form
 *                    Av(x) = f(x),
 * where A is a nxn tridiagonal matrix, and v(x) and f(x) are vectors
 * on the interval [1, n]
 **/

#include <iostream>
#include <armadillo>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "ctime"
using namespace std;
using namespace arma;

//Functions used
vec generalAlgorithm(int n, mat A, vec f);
vec optimizedAlgorithm(int n, mat A, vec f);
vec LUdecompAlgorithm(int n, mat A, vec f);

inline double sourceFunc(double x){
        return 100.0*exp(-10.0*x);
}
inline double exactSol(double x){
        return 1.0-(1-exp(-10))*x-exp(-10*x);
}

int main(int argc, char *argv[])
{
        int n;
        n = atoi(argv[1]);     // Read n as cmd-line argument

        mat A(n,n,fill::zeros);
        vec f(n);
        vec v1(n);   // Store result from General Algorithm
        vec v2(n);   // Store result from Optimized Algorithm
        vec v3(n);   // Store result from LU-decomposition Algorithm
        vec x(n);

        double h = 1.0/((double) n-1);  // Step-size
        // Fill tridiagonal matrix
        A.diag(0).fill(2);
        A.diag(1).fill(-1);
        A.diag(-1).fill(-1);
        // Fill vectors
        for (int i=0; i<n; i++) {
                x[i] = i*h;
                f[i] = pow(h,2)*sourceFunc(x[i]);
        }

        // Solve
        v1 = generalAlgorithm(n, A, f);
        v2 = optimizedAlgorithm(n, A, f);
        v3 = LUdecompAlgorithm(n, A, f);

        // Write data to file
        ofstream myfile;
        myfile.open("project1_results.txt");
        for(int i = 0; i < n; i++) {
                myfile << x[i] << " " << v1[i] << " " << v2[i] << " " <<
                        v3[i] << endl;
        }
        myfile.close();
        cout << "Done!" << endl;

        return 0;
}


vec generalAlgorithm(int n, mat A, vec f)
{
        vec v(n);
        // Boundary & Initial Conditions:
        v[0] = v[n-1] = 0.0;
        // Forward substitution:
        for (int i=2; i < n-1; i++) {
                A(i,i) -= (A(i-1, i)*A(i, i-1))/A(i-1, i-1);
                f[i] -= (A(i-1, i)*f[i-1])/A(i-1, i-1);

        }
        // Backward substitution:
        for (int i=n-2; i > 0; i--) {
                v[i] = (f[i] - A(i, i+1)*v[i+1])/A(i, i);
        }

        return v;
}

vec optimizedAlgorithm(int n, mat A, vec f)
{
        vec v(n);
        // Boundary & Initial Conditions:
        v[0] = v[n-1] = 0.0;

        // Forward substitution:
        for (int i=2; i < n-1; i++) {
                A(i,i) -= 1.0/A(i-1, i-1);
                f[i] += f[i-1]/A(i-1, i-1);
        }
        // Backward substitution:
        for (int i=n-2; i > 0; i--) {
                v[i] = (f[i] + v[i+1])/A(i, i);
        }

        return v;
}

vec LUdecompAlgorithm(int n, mat A, vec f)
{
        vec v(n);
        mat L,U,P;             // Initialize matrices L, U, P for decomposition
        lu(L,U,P,A);           // Perform LU-decomposition
        mat Y = solve(P*L, f);
        v  = solve(U, Y);
        // Boundary & Initial Conditions:
        v[0] = v[n-1] = 0.0;

        return v;
}


/*
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
 */
