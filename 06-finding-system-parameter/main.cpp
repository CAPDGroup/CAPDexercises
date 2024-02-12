#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Find parameter of a system subject to some constraint.
 * For detailed description of the problem see README.md file
*/

int main(){
  cout.precision(17);
  const interval x0 = 0;
  const interval x1 = 2;
  const interval L = 1;
  const interval v = 0.5;
  IMap vf("par:pi,L,v;time:t;var:x,a;fun:cos((0.5*pi/L)*(t*(v*sin(a))-L))+v*cos(a),0;");
  vf.setParameter("pi",interval::pi());
  vf.setParameter("L",L);
  vf.setParameter("v",v);
  IOdeSolver solver(vf,20); // Ode solver of order 20
  ITimeMap tm(solver);      // for long time intergration
  
  
  // Approximate parameter:
  interval a = 1.9058939019661396;
  IVector u0{x0,a};
  C0HORect2Set s(u0);
  interval T = 2.0*L/(v*sin(a));
  cout << "approximation: " << tm(T,s) << endl; // the x-component of the result is almost x1=10 
  
  // Hint 
  // 1) Use vf to compute nonautonomous vector field for a given time and at a given point
  cout << "vector field: " << vf(T,u0) << endl << endl;
  
  // #include "solution.h"
}
