1. It can be contigious/non-contagious sequence which follows the order.

##Important recursive pattern:

f(A,i,s) {
  //BC
  if(i>=n) {
    print(s)
    return
  }
  // Include A[i]
  s.push_back(A[i]);
  f(A,i+1,s);
  while(i+1<n && A[i]==A[i+1]) i++;
  s.pop_back();

  // Not include A[i]
  f(A,i+1,s);
}