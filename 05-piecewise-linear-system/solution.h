// Solution  
{
  double e = 1e-4;
  IVector u1, u2;
  
  C0Rect2Set s1({0.0,u[1]-e,0.0});
  u1 = pm1(s1);
  C0Rect2Set s2(u1);
  u2 = pm2(s2);
  interval zL = u2[2];
  
  s1 = C0Rect2Set({0.0,u[1]+e,0.0});
  u1 = pm1(s1);
  s2 = C0Rect2Set(u1);
  u2 = pm2(s2);
  interval zR = u2[2];

  // check the existence of solution over line segment
  s1 = C0Rect2Set({0.0,u[1]+interval(-e,e),0.0});
  u1 = pm1(s1);
  s2 = C0Rect2Set(  u1);
  u2 = pm2(s2);
  cout << u2 << endl;

  cout << "Result: " << (zL*zR<0) << endl;
}
