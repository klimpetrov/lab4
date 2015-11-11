#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin){
   ofstream out("output.txt");
   for(int i=0; i<N; i++){
     
       out << i*dx + xmin << "\t" << p[i] << endl;
      
       cout << i*dx + xmin << "\t" << p[i] << endl;
    }
out.close();
}
void rein(double* p, const double xmin, const int N, const double dx){
    for(int i=0; i<N; i++){
	p[i] = exp(-pow(xmin+i*dx,2));
    }
}

void abl(double* p, const int N, const double dx){
    double a,b;
    p[0]=0;
    p[N-1] =0;
    b = 0;
  for(int i=1; i<N-1; i++){
    a=p[i];
   p[i] = (p[i+1]-b)/(2*dx);
    b=a;
  }
}

int main(){
 
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  rein(p, xmin,N, dx);
  
  // call to functio which calculates the derivative
  abl(p, N, dx);
  print(p,N,dx,xmin);
 

  return 0;
}
