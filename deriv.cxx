#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void Funktion(double* x, double xmax, double xmin, double dx, int N){
 for(int i = 0; i <= N; i++){
   x[i] = (double)exp(-(xmin+(i*dx))*(xmin+(i*dx)));
   //cout << x[i] <<endl;
 }
}

void deriv(double* x,double dx, int N){
  double a = x[0];
  for(int i = 1; i <= N-1; i++){
  double b = x[i];
  x[i] = ((x[i+1]-a)/(2*dx));
  a = b;
  }
  x[0] = 0;
  x[N] = 0;
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  Funktion(p,xmax,xmin,dx, N);
  // call to functio which calculates the derivative
  deriv(p, dx, N);
  print(p,N,dx,xmin);

  return 0;
}
