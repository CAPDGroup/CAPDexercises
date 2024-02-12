#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Find parameter of a system that minimizes certain property of this system
 * For detailed description see README.md file.
*/

int main(){
  cout.precision(17);
  const interval x0 = 0;
  const interval x1 = 2;
  const interval L = 1;
  const interval v = 0.5;
  const interval k = 2.0*L/v;
  
  IMap vf("par:pi,L,v;time:t;var:x,a;fun:cos((0.5*pi/L)*(t*(v*sin(a))-L))+v*cos(a),0;",2);
  vf.setParameter("pi",interval::pi());
  vf.setParameter("L",L);
  vf.setParameter("v",v);
  IC2OdeSolver solver(vf,6);
  IC2TimeMap tm(solver);
  
  // Approximate parameter:
  interval a =  2.4741354375614257;
  IVector u0{x0,a};
  interval T = k/sin(a);
  
  // Hint 
  // 1) Integration of second order variational equations
  C2Rect2Set s(u0,2); // 2 for second order derivatives
  tm(T,s);
  cout << "Second derivative x(T,x0) wrt to parameter: " << 2*s(0,1,1) << endl;
  // indexing 0-component, derivative wrt 1-variable and 1-variable, that is second wrt. alpha 
  // Note: this is not the second derivative of g.
  
  // 2) A formula for second or higher order time derivatives of a nonautonomous system can be derive manually, but there is a library routine for this:
  
  IVector coeffs[3]={u0,u0,u0}; // first element is IVP, remaining will be overwritten by computeODECoefficients
  vf.setCurrentTime(0.0);
  vf.computeODECoefficients(coeffs,2);
  for(int i=0;i<3;++i)
    cout << "Taylor coeffs[" <<i << "]=" << coeffs[i] << endl;
   
  // #include "solution.h"
}
