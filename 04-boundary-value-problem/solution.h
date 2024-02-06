// Solution
{
  C0Rect2Set s0({x0,y0,px,py});
  IVector u = tm(T,s0);
  interval s = 1e-5*interval(-1,1);
  px += s;
  py += s;
  C1Rect2Set s1({x0,y0,px,py});
  tm(T,s1);
  IMatrix D = (IMatrix)s1;
  IMatrix M({{D[0][2],D[0][3]},{D[1][2],D[1][3]}});
  IVector z = -matrixAlgorithms::gauss(M,IVector{u[0]-x1,u[1]-y1});
  cout << z << endl;
  cout << (subset(z[0],s) and subset(z[1],s)) << endl; 
}
