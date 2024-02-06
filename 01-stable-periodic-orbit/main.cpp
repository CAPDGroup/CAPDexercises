#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Validate the existence of a stable periodic orbit in the van der Pol equation
 * 
 * Methodology:
 * 1) Fix Poincare section Pi = {(x,0) : x\in R}
 * 2) Take an interval X=([x1,x2],0) \subset Pi
 * 3) Show that P(X)\subset X (existence validated)
 * 4) Show that |\partial P/\parial x (X)|<1 and thus the orbit is stable
 * 
*/

int main(){
  cout.precision(17);
  IMap vectorField("par:c;var:x,y;fun:y,c*y*(1-x^2)-x;"); // van der Pol 
  vectorField.setParameter("c",interval(2)/interval(10));
  IOdeSolver solver(vectorField,20); // Ode solver of order 20
  ICoordinateSection section(2,1);   // Poincare section y=0 (two variables, index of y is 1)
  IPoincareMap pm(solver,section,poincare::PlusMinus); // define Poincare map on the section with crossing direction from plus to minus
  
  IVector u({2.0004136789920905, 0.0}); // approximate fixed point for Poincare map

  // Add here few lines that check existence and stability of periodic orbit
    
  // Hints:
  
  // 1) Computation of Poincare map
  C0Rect2Set s0(u);
  cout << pm(s0) << endl;
  
  // 2) Computation of derivative of Poincare map
  C1Rect2Set s1(u);
  IMatrix flowDerivative(2,2);
  IVector v = pm(s1,flowDerivative);
  IMatrix poincareMapDerivative = pm.computeDP(v,flowDerivative);
  cout << poincareMapDerivative << endl;
  interval dPdx = poincareMapDerivative[0][0];
  cout << dPdx << endl;

  // 3) Use global function subset(x,y) which checks if the interval x is a subset of the interval y.
  
 // #include "solution.h"
}
