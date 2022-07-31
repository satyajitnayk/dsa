A =  [ 1, 3, 2, 4]
NGL =[-1,-1, 3,-1]

Approach 1: BF
for(int i=0 ; i<n; ++i) {
  for(int j=i-1; j>=0; -j) {
    //
  }
}

*** j is depenedent on i => stack can be used to solve this problem

Approach 2: Using stack to store greatest elements to left
->Traverse from L->R

stack<int> s;
vector<int> ngl;
for(int i=0; i<n; ++i) {
  if(s.size() == 0) ngl.push_back(-1);
  else if(s.size() > 0 && s.top() > A[i]) {
    ngl.push_back(s.top());
  } else if(s.size() > 0 && s.top() <= A[i]) {
    while(s.size() > 0 && s.top() <= A[i]) s.pop();
    if(s.size() > 0) ngl.push_back(s.top());
    else ngl.push_back(-1);
  }
  s.push(A[i]);
}

=> Time O(n) & space O(n)