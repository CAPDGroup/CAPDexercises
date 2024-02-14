// Solution
{
  C0TripletonSet s0(u0);
  IVector v0 = pm(s0);  
  interval r = 1e-10*interval(-1,1);
  C1Rect2Set s1({0.,u0[1]+r,u0[2]+r});
  IMatrix flowDerivative(3,3);
  IVector v = pm(s1,flowDerivative);
  IMatrix DP = pm.computeDP(v,flowDerivative);
  
  // take 2D projection of DP-Id and compute interval Newton operator
  IMatrix M{{DP[1][1]-1.0,DP[1][2]},{DP[2][1],DP[2][2]-1.0}};
  IVector N = - matrixAlgorithms::gauss(M,IVector{v0[1]-u0[1],v0[2]-u0[2]});
  cout << "Result: " << ( subset(N[0],r) and subset(N[1],r)) << endl;

 // explicit formula for eigenvalues of a 2x2 matrix
  interval m = 0.5*(DP[1][1]+DP[2][2]);
  interval d = DP[1][1]*DP[2][2]-DP[1][2]*DP[2][1];
  interval t = sqrt(sqr(m)-d);
  cout << "lambda1=" << m-t << endl;
  cout << "lambda2=" << m+t << endl;
}
