#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * 
 * This is a continuation od exercise 06-finding-system-parameter, 
 * so please read first its description.
 * 
 * Assume additionally, that the current of river is larger than the velocity of the boat.
 * Then, the boat must be drifted and there is a minimal recheable point (x1,L) by the boat.
 * Here we find a local minium, only.
 * 
 * Problem:
 *    Find (local) minumum x1(\alpha) and find control parameter (\alpha) for which this minimum is taken.    
 * 
 * Methodology:
 *  1) The motion in x-direction is modeled by a nonatunomous equation
 *        x' = cos(y\pi/(2L)) + v\cos\alpha
 *           = cos( (t*v\sin\alpha-L)*\pi/(2L) ) + v\cos\alpha
 *  3) We would like to find minimum of 
 *        g(\alpha) = \phi(T(\alpha),x0)
 *     or zero of its derivative
 *  4) It would be be helpful to have second order derivatives of g, 
 *     that involve second order variational equations to be solved.
 *  
 * Data:
 *    L = 1
 *    v = 0.5
 *    x0 = 0, y0 = -L
 *    x1 = 2, y1 = L
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
  interval a =  2.471354375614129;
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
