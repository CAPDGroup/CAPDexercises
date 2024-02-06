#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Check, that a there is an odd periodic solution to the following piecewise linear system.
 *  x''' + x' + |x|/2 = 1
 * 
 * Methodology:
 *  1) Rewrite the system as first order
 *      x' = y
 *      y' = z
 *      z' = 1-y-|x|/2
 *  2) The system is reversible -- symmetric wrt. y axis
 *  3) Poincare map P:Pi\to Pi, where Pi = {(0,y,z)} is also reversible
 *  4) Due to the symmetry is suffices to show that there is (0,y0,0) such that 
 *     P^n(0,y0,0) = (0,y1,0) for some y1 and n>0
 *     Then the orbit must be closed.
 *  5) Use shooting - show that for some a,b the Poincare map is defined on line segment [a,b] and
 *     \pi_z P(0,a,0)*\pi_z P(0,b,0)<0
 * 
*/

int main(){
  cout.precision(17);
  IMap vf1("par:c;var:x,y,z;fun:y,z,1-y-0.5*x;"); // for x>=0
  IMap vf2("par:c;var:x,y,z;fun:y,z,1-y+0.5*x;"); // for x<0
  IOdeSolver solver1(vf1,20); // Ode solver of order 20
  IOdeSolver solver2(vf2,20); // Ode solver of order 20
  ICoordinateSection section(3,0); // x=0
  IPoincareMap pm1(solver1,section);
  IPoincareMap pm2(solver2,section);
  
  // Approximate periodic point:
  IVector u{0.0,1.3744,0.0};
  C0Rect2Set s1(u);
  IVector u1 = pm1(s1);
  C0Rect2Set s2(u1);
  IVector u2 = pm2(s2);

  // the z-th coordinate of the above should be close to zero
  cout << u2 << endl;
  
//  #include "solution.h"
}
