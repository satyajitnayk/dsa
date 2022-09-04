10C4 = (10*9*8*7)/(1*2*3*4)

mCn

#CODE
int solve(int n, int r) {
  double res = 1;
  for(int i=1;i<=r;++i) {
    res *= (n-r+i) / i;
  }
  return res;
}