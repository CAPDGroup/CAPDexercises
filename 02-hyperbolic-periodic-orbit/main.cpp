#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Show the existence of a hyperbolic periodic orbit for the Roessler system. 
 * See README.md for description of the problem.
*/

int main(){
  cout.precision(17);
  IMap vectorField("par:a,b;var:x,y,z;fun:-(y+z),x+b*y,b+z*(x-a);");
  vectorField.setParameter("a", interval(57)/interval(10));
  vectorField.setParameter("b", interval(2)/interval(10));
  IOdeSolver solver(vectorField,20); // Ode solver of order 20
  ICoordinateSection section(3,0);   // Poincare section x=0
  IPoincareMap pm(solver,section,poincare::MinusPlus); // define Poincare map on the section with crossing direction from minus to plus
  
  // An approximate solution
  IVector u0{0.,-8.3809417428298,0.029590060630665};
  C0TripletonSet s(u0);
  // show this is indeed an approximate fixed point
  cout << pm(s) - u0 << endl; // should be close to zero 
    
  // Hints:  
  // 1) Computation of derivative of Poincare map
  C1Rect2Set s1(u0);
  IMatrix flowDerivative(3,3);
  IVector v = pm(s1,flowDerivative);
  IMatrix DP = pm.computeDP(v,flowDerivative);
  cout << DP << endl; 
  // 2) Use global function subset(x,y) which checks if the interval x is a subset of the interval y.
  
  //#include "solution.h"
}
