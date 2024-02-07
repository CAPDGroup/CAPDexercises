// Solution  
{
  double e = 1e-6;
  C0Rect2Set s0(IVector{x0,-L,a});
  interval xT = tm(2.0/sin(a),s0)[0] - x1;
  
  interval A = a+interval(-e,e);
  C1Rect2Set s1(IVector{x0,-L,A});
  IVector z = tm(2.0/sin(A),s1);
  interval dT = -2.*vf(z)[0]*cos(A)/sqr(sin(A)) + ((IMatrix)s1)[0][2];
  
  interval N = -xT/dT;
  cout << "Bound for a: " << a + N << endl;
  cout << "Result: " << (abs(N)<e) << endl;
}
