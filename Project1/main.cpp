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
#include <chrono>
using namespace std;
using namespace arma;

//Functions used
vec generalAlgorithm(int n, mat A, vec f);
vec optimizedAlgorithm(int n, mat A, vec f);
vec LUdecompAlgorithm(int n, mat A, vec f);
void relativeError();

inline double sourceFunc(double x){
        return 100.0*exp(-10.0*x);
}
inline double exactSol(double x){
        return 1.0-(1-exp(-10))*x-exp(-10*x);
}

// Begin main program
int main(int argc, char *argv[])
{
        int n;                 // Number of grid-points
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

        // Solve and clock performance
        auto start_1 = chrono::high_resolution_clock::now();  // Start clock 1
        v1 = generalAlgorithm(n, A, f);
        auto finish_1 = chrono::high_resolution_clock::now(); // Stop clock 1

        auto start_2 = chrono::high_resolution_clock::now();  // Start clock 2
        v2 = optimizedAlgorithm(n, A, f);
        auto finish_2 = chrono::high_resolution_clock::now(); // Stop clock 2

        auto start_3 = chrono::high_resolution_clock::now();  // Start clock 3
        v3 = LUdecompAlgorithm(n, A, f);
        auto finish_3 = chrono::high_resolution_clock::now(); // Stop clock 3

        chrono::duration<double> elapsed_1 = finish_1 - start_1;
        chrono::duration<double> elapsed_2 = finish_2 - start_2;
        chrono::duration<double> elapsed_3 = finish_3 - start_3;

        cout << "General Algorithm with n=" << n <<
                " gridpoints elapsed time:" << elapsed_1.count() << endl;
        cout << "Optimized Algorithm with n=" << n <<
                " gridpoints elapsed time:" << elapsed_2.count() << endl;
        cout << "LU-decomposition Algorithm with n=" << n <<
                " gridpoints elapsed time:" << elapsed_3.count() << endl;

        // Relative error
        relativeError();

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
// End main program

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
        //X.submat( first_row, first_col, last_row, last_col )
        //V.subvec( first_index, last_index )

        // Remove endpoints
        //n = n-1;
        mat A2 = A.submat(1, 1, n-1, n-1);
        vec f2 = f.subvec(1, n-1);

        vec v(n);
        v[1] = v[n-1] = 0.0;
        mat L,U,P;             // Initialize matrices L, U, P for decomposition
        lu(L,U,P,A2);           // Perform LU-decomposition
        mat Y = solve(P*L, f2);
        v  = solve(U, Y);
        // Boundary & Initial Conditions:
        //v[1] = v[n-1] = 0.0;

        return v;
}

void relativeError()
{
        int k = 7;
        vec eps(k);
        vec h_err(k);

        for (int j=1; j < k+1; j++ ) {
                int n = pow(10, j);

                vec f(n);
                vec x(n);
                vec b(n);
                vec v(n);
                vec epsilon(n);
                double max_eps;

                double h = 1.0/((double) n-1);  // Step-size

                // Fill vectors
                for (int i=0; i<n; i++) {
                        b[i] = 2.0;
                        x[i] = i*h;
                        f[i] = pow(h,2)*sourceFunc(x[i]);
                }
                // Solve using Optimized Algorithm:
                // Forward substitution:
                for (int i=2; i < n-1; i++) {
                        b[i] -= 1.0/b[i-1];
                        f[i] += f[i-1]/b[i-1];
                }
                // Backward substitution:
                for (int i=n-2; i > 0; i--) {
                        v[i] = (f[i] + v[i+1])/b[i];
                }

                max_eps = log10(abs((v[1]-exactSol(x[1]))/exactSol(x[1])));
                for (int i=2; i<n-1; i++) {
                        epsilon[i] = log10(abs((v[i]-exactSol(x[i]))/exactSol(x[i])));
                        if (epsilon[i] > max_eps)
                                max_eps = epsilon[i];
                }


                h_err[j-1] = h;
                eps[j-1] = max_eps;

        }
        // Write data to file
        ofstream myfile;
        myfile.open("RelativeError.txt");
        for(int j = 0; j < k; j++) {
                myfile << h_err[j] << " " << eps[j] << endl;

        }
        myfile.close();
}
