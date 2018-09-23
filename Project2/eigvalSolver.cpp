#include "eigvalSolver.h"

double maxElement(mat &A, int &k, int &l, int N)
{
		double max = 0.0;
		for (int i=0; i<N; i++) {
				for (int j=i+1; j<N; j++) {
						if (fabs(A(i,j)) > max) {
								max = fabs(A(i,j));
								l = i;
								k = j;
						}
				}
		}
		return max;
}

void jacobiRotate(mat &A, int k, int l, int N)
{
		double A_kk = A(k, k);
		double A_ll = A(l, l);
		double A_kl = A(k, l);
		double t, s, c;
		double tau = (A_ll - A_kk)/(2*A_kl);

		if (tau > 0) {t = 1.0/(tau + sqrt(1.0 + tau*tau));}
		else {t = -1.0/( -tau + sqrt(1.0 + tau*tau));}

		c = 1/sqrt(1+t*t);
		s = t*c;

		for (int i=0; i<N; i++) {
				double temp = A(i,k);
				A(k,i) = A(i, k) = A(i, k)*c - A(i, l)*s;
				A(l, i) = A(i, l) = A(i,l)*c + temp*s;
		}

		A(k, k) = c*c*A_kk - 2.0*c*s*A_kl + s*s*A_ll;
		A(l, l) = s*s*A_kk + 2.0*c*s*A_kl + c*c*A_ll;
		A(k, l) = A(l, k) = 0.0;
}


vec jacobiMethod(mat &A, int N)
{
		int k, l;
		double max = 1;
		double eps = 1e-10;

		int iterations = 0;
		while(max>eps)
		{
				max = maxElement(A, k, l, N);
				jacobiRotate(A, k, l, N);
				iterations++;
		}
		cout << "Number of iterations: " << iterations << endl;

		vec eigval = A.diag(0);
		eigval = sort(eigval);
		return eigval;
}


vec armaSolve(mat A)
{
		vec eigval;
		mat eigvec;
		eig_sym(eigval, eigvec, A);
		return eigval;
}
