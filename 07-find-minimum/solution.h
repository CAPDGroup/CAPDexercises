// Solution  
{
  // g(a) := x(T(a),a) // skip dependency on x0
  // g'(a) = x_t(T(a),a)*T'(a) + x_a(T(a),a) = f(T(a),a)*T'(a) + x_a(T(a),a)
  // g''(a)= (x_tt*T' + vf_a)*T' + x_t T" + vf_a*T' + x_aa
  //       = (x_tt*T' + 2vf_a)*T' + x_t T" + x_aa

  double e = 1e-12;
  C1HORect2Set s1(IVector{x0,a});
  interval T = k/sin(a);
  IVector z = tm(T,s1);
  interval dg = vf(T,z)[0]*(-k)*cos(a)/sqr(sin(a)) + ((IMatrix)s1)[0][1]; // f(T(a),a)*T'(a) + x_a(T(a),a)
  
  // travelling time and its derivatives wrt angle
  interval A = a+interval(-e,e);
  interval s = sin(A), c = cos(A);
  T = k/s;
  interval dT = -k*c/sqr(s);
  interval d2T = k*(sqr(c)+1)/power(s,3);

  C2Rect2Set s2(IVector{x0,A});
  z = tm(T,s2);
  IVector coeffs[3]={z,z,z};
  IMatrix D = vf.derivative(T,z);
  vf.setCurrentTime(T);
  vf.computeODECoefficients(coeffs,2);
  interval d2g = 2.0*dT*(coeffs[2][0]*dT + D[0][1]) + coeffs[1][0]*d2T + 2.*s2(0,1,1); // (x_tt*T' + 2vf_a)*T' + x_t T" + x_aa
  interval N = -dg/d2g;

  cout << "dg: " << dg << endl;
  cout << "d2g: " << d2g << endl;
  cout << "Bound for a: " << a + N << endl;
  cout << "Bound for x1: " << z[0] << endl;
  cout << "Result: " << (abs(N)<e) << endl;
}
