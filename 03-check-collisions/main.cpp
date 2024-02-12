#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Check, that a set of trajectories over an explicit time range does not hit an obstacle.
 * For detailed description see README.md
 * 
*/

int main(){
  cout.precision(17);
  IMap vectorField("par:c;var:x,y,z;fun:y,z,c^2-y-0.5*x^2;"); // The Michelson system 
  vectorField.setParameter("c",0.125);
  IOdeSolver solver(vectorField,20); // Ode solver of order 20
  ITimeMap tm(solver); // long-time integrator of the system
  
  // IVP:
  const interval T = 100;

  // Hint:
  // Record the entire trajectory segment and then evaluate it
  ITimeMap::SolutionCurve solution(0.0); // init solution object
  C0HOTripletonSet s({0.,-0.125,0.}); // use high order Hermite-Obreshkov method to integrate
  tm(T,s,solution); // record trajectory
  cout << "solution(7) \\in " << solution(7.) << endl;  

//  #include "solution.h"
}
