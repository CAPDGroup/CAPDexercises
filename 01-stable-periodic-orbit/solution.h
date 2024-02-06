// Solution
{
  interval s = 1e-5*interval(-1,1);
  C1Rect2Set s1({u[0]+s,0.});
  IMatrix flowDerivative(2,2);
  IVector v = pm(s1,flowDerivative);
  IMatrix poincareMapDerivative = pm.computeDP(v,flowDerivative);
  cout << v[0]-u[0] << endl; // should be subset of s
  cout << poincareMapDerivative[0][0] << endl; // should be abs(DP/dx)<1
  cout << "Result: " << ( subset(v[0]-u[0],s) and abs(poincareMapDerivative[0][0])<1.0) << endl;
}
