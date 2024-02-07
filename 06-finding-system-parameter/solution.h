// Solution  
{
  double e = 1e-6;
  C0Rect2Set s0(u0);
  interval T = 2.0/sin(a);
  interval xT = tm(T,s0)[0] - x1;
  
  interval A = a+interval(-e,e);
  IVector u{x0,-L,A};
  T = 2.0/sin(A);
  C1Rect2Set s1(u);
  IVector z = tm(T,s1);
  interval dT = -2.*vf(z)[0]*cos(A)/sqr(sin(A)) + ((IMatrix)s1)[0][2];
  
  interval N = -xT/dT;
  cout << "Bound for a: " << a + N << endl;
  cout << "Result: " << (abs(N)<e) << endl;
}
