#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Find parameter of the system such that x(0)=x0 and x(T)=x1
 * 
 * Consider a model of boat traveling through the river of width 2L: y\in[-L,L]
 *  
 * We assume that the current of the river is given by v(y) = cos(y\pi/(2L)).
 * The boat has constant velocity v but in the direction specified by the angle \alpha
 * 
 * Problem: 
 *    Find constant \alpha such that the boat starting from x(0)=x0, y(0)=-L reaches the point x(T)=x1 and y=L.
 * 
 * Methodology:
 *  1) The boat is traveling in y-direction with constant velocity v\sin\alpha. 
 *     Thus the traveling time must be T=2L/(v\sin\alpha)
 *  2) The motion in x-direction is modeled by 
 *        x' = cos(y\pi/(2L)) + v\cos\alpha
 *  3) We have to solve equation 
 *        x(T) = x(2L/(v\sin\alpha)) = x1
 *  4) Apply interval Newton method to:
 *     f(a) = \phi_x(T(a),(x0,-L,a)) - x1 = 0
 * 
 * Data:
 *    L = 1
 *    v = 1
 *    x0 = 0, y0 = -L
 *    x1 = 10, y1 = L
*/

int main(){
  cout.precision(17);
  IMap vf("par:pi;var:x,y,a;fun:cos((0.5*pi)*y)+cos(a),sin(a),0;");
  vf.setParameter("pi",interval::pi());
  IOdeSolver solver(vf,20); // Ode solver of order 20
  ITimeMap tm(solver);
  
  const interval x0 = 0;
  const interval x1 = 10;
  const interval L = 1;
  
  // Approximate parameter:
  interval a = 0.32257362709086951;
  IVector u0{x0,-L,a};
  C0Rect2Set s(u0);
  interval T = 2.0/sin(a);
  cout << tm(T,s) << endl; // the x-component of the result is almost x1=10 
  
  // Hint 
  // 1) Use vf to compute vector field at a given point, for example
  cout << f(u0) << endl;
  
  #include "solution.h"
}
