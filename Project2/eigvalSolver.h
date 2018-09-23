#include <iostream>
#include <cmath>
#include <armadillo>

using namespace  std;
using namespace  arma;

double maxElement(mat &A, int &k, int &l, int N);
void jacobiRotate(mat &A, int k, int l, int N);
vec jacobiMethod(mat &A, int N);
vec armaSolve(mat A);
