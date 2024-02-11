// Solution  
{
  double e = 1e-11;
  C0HORect2Set s0(IVector{x0,a});
  interval xT = tm(2.0*L/(v*sin(a)),s0)[0] - x1;
  
  interval A = a+interval(-e,e);
  C1HORect2Set s1(IVector{x0,A});
  T = 2.0*L/(v*sin(A));
  IVector z = tm(T,s1);
  interval dT = vf(T,z)[0]*(-2.*L/v)*cos(A)/sqr(sin(A)) + ((IMatrix)s1)[0][1];
  
  interval N = -xT/dT;
  cout << "Bound for a: " << a + N << endl;
  cout << "Result: " << (abs(N)<e) << endl;
}
