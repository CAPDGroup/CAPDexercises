#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Check, that a set of trajectories over an explicit time range does not hit an obstacle.
 * 
 * Methodology:
 *  1) "Record" solutions to IVP as a SolutionCurve object
 *  2) Subdivide time range and check the required constraint (avoiding obstacle) for each time-subinterval
 * 
 * The Michelson system:
 *   x'=y, y'=z, z'= c^2 - y - \frac{1}{2}x^2,   c = 1/8
 * 
 * IVP:
 *   x(0) = 0
 *   y(0) = -0.125 + e, 
 *   z(0) = e, 
 *   e \in 10^{-4}*[-1,1]  
 * 
 * Constraint for the Euclidean norm along the solution:
 *   | (x(t),y(t),z(t))| >= 0.1
 * for
 *   t \in [0,100]
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
