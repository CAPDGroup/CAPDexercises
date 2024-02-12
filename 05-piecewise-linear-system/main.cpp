#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Check, that a there is an odd periodic solution to a piecewise linear system.
 * For detailed description see README.md
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
