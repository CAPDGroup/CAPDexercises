#include <iostream>
#include "capd/capdlib.h"
using namespace std;
using namespace capd;

/**
 * EXERCISE:
 * Find parameter of a system subject to some constraint.
 * 
 * Consider the model of a boat traveling through a river of width 2L: y\in[-L,L]
 *  
 * We impose that the current of the river is given by V(x,y) = (cos(y\pi/(2L)),0).
 * The boat has constant velocity v but in the direction specified by the angle \alpha
 * 
 * Problem: 
 *    Find constant \alpha such that the boat starting from x(0)=x0, y(0)=-L reaches the point x(T)=x1 and y=L for some T>0.
 * 
 * Methodology:
 *  1) The boat is travelling in y-direction with constant velocity v\sin\alpha. 
 *     Thus y(t) = -L + t*v\sin\alpha
 *     and the travelling time to a point y(t)=L must be T=2L/(v\sin\alpha)
 *  2) The motion in x-direction is modeled by a nonatunomous equation
 *        x' = cos(y\pi/(2L)) + v\cos\alpha
 *           = cos( (t*v\sin\alpha-L)*\pi/(2L) ) + v\cos\alpha
 *  3) We have to solve the equation 
 *        x(2L/(v\sin\alpha)) = x1
 *     for \alpha.
 *  4) Apply interval Newton method to:
 *     f(\alpha) = \phi(T(\alpha),x0) - x1 = 0
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
  IMap vf("par:pi,L,v;time:t;var:x,a;fun:cos((0.5*pi/L)*(t*(v*sin(a))-L))+v*cos(a),0;");
  vf.setParameter("pi",interval::pi());
  vf.setParameter("L",L);
  vf.setParameter("v",v);
  IOdeSolver solver(vf,20); // Ode solver of order 20
  ITimeMap tm(solver);      // for long time intergration
  
  
  // Approximate parameter:
  interval a = 1.9058939019661396;
  IVector u0{x0,a};
  C0Rect2Set s(u0);
  interval T = 2.0*L/(v*sin(a));
  cout << "approximation: " << tm(T,s) << endl; // the x-component of the result is almost x1=10 
  
  // Hint 
  // 1) Use vf to compute nonautonomous vector field for a given time and at a given point
  cout << "vector field: " << vf(T,u0) << endl << endl;
  
  // #include "solution.h"
}
