#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Validate the existence of a solution to a BVP u(0)=u0, u(T)=u1 for a 2DOF Henon-Heiles hamiltonian:
 *   x" = -x*(1+2*y),     y" = y*(y-1)-x^2 
 *  where u=(x,y).
 * 
 * Methodology:
 *   Solve equation 
 *      F(u'(0)) := \pi_u\phi(T,(u0,u'(0)))-u1 = 0
 *   for u'(0) using for example the Interval Newton Method,
 *   where 
        \pi_u is the projection onto u-coordinate 
 *   and
 *      \phi(t,u,u') is the underlying flow.
 * 
 * BVP:
 *  T  = 1
 *  u(0) = (1,0)
 *  u(T) = (0,1)
*/

int main(){
  cout.precision(17);
  IMap vectorField("var:x,y,px,py;fun:px,py,-x*(1+2*y),y*(y-1)-x^2;"); // Henon-Heiles hamiltonian
  IOdeSolver solver(vectorField,15); // Ode solver of order 20
  ITimeMap tm(solver); // long-time integrator of the system
  
  // BVP:
  const interval T = 1.0;
  const interval x0 = 1.0;
  const interval y0 = 0.0;
  const interval x1 = 0.0;
  const interval y1 = 1.0;
  
  // Approx solution
  interval px = -0.36331582018346342;
  interval py = 1.4091573668228699;

  // Test that this is indead an approximate solution
  C0Rect2Set s0({x0,y0,px,py});
  cout << tm(T,s0) << endl;
  
  // Hints
  // 1) Computation of derivative of flow
  C1Rect2Set s1({x0,y0,px,py});
  IVector y = tm(T,s1);
  IMatrix D = (IMatrix)s1;
  cout << D << endl;
  
  // 2) solving linear equations (D^{-1}*y)
  cout << matrixAlgorithms::gauss(D,y) << endl;
  
// #include "solution.h"  
}
