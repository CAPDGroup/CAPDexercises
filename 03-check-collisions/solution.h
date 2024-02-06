// Solution  
{
  ITimeMap::SolutionCurve solution(0.0);
  interval e = interval(-1,1)/10000; // +/- 10^{-4}
  C0HOTripletonSet s({0.,-0.125+e,e});
  tm(T,s,solution);

  int N = 200; // just uniform subdivision, 200 from trials  
  for(int i=0;i<N;++i){
    interval t = interval(i,i+1)*T/N;
    interval norm = solution(t).euclNorm();
    if( not (norm>=0.1) ) {
      cout << "Constraint not satisfied: t=" <<  t << ", norm= " << norm << endl;
      break;
    }
  }
}
