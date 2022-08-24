Time O(n) & space O(1)

double myPow(double x, int n) {
    double ans = 1;
    while(n) {
      //if n is odd ans=ans*x based on value of n >0 or not
      if(n%2) ans = n > 0 ? ans*x : ans/x;
      x *= x;
      n /= 2;
    }
    return ans;
}