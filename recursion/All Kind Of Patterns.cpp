Type 1:Print any one 

bool f() {
  if(base condition) {
    if(condition satisfied) return true;
    return false;
  }

  if(f() === true) return true;

  if(f() == true) return true;

  return false;
}

#Example: Print any one subsequence with sum K.

bool printS(int i,vector<int> &A, vector<int> &v,int s, int target) {
  if(s>target) return false;
  if(i==n) {
    if(s == target) {
      cout << v << "\n";
      return true;
    }
    return false;
  }

  v.push_back(A[i]);
  s += A[i];
  if(printS(i+1,A,v,s,target) == true) return true;

  v.pop_back();
  s -= A[i];
  if(printS(i+1,A,v,s,target) == true) return true;

  return false;
}


Type 2:Return count of patterns.

f() {
  base case {
    if(condition satisfied) return 1;
    return 0;
  }
  l = f() 
  r = f()
  ....
  return l + r + ...;
}
