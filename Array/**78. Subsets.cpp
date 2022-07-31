Approach 1 :Backtracking
=>Time O(n*2^n) & space O(n)

void solve(vector<int> A, int idx,vector<int> ss) {
    // BC
    if(idx >= A.size()) {
        s.insert(ss);
        return;
    }
    solve(A,idx+1,ss);
    ss.push_back(A[idx]);
    solve(A,idx+1,ss);
}
vector<vector<int>> subsets(vector<int>& A) {
    vector<int> ss;
    solve(A,0,ss);
    vector<vector<int>> ans;
    for(auto &v:s) {
        ans.push_back(v);
    }
    return ans;
}

Approach 2: Iterative Approach
   
->[1, 2, 3]
->Initially empty set ans = [[]]
-> add 1 => [[],[1]]
-> add 2 => [[],[1],[2],[1,2]]
-> add 3 => [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

=> Time O(n*2^n) & space O(1)

vector<vector<int>> subsets(vector<int>& A) {
    vector<vector<int>> ans = {{}};
    for(auto c:A) {
        int n = ans.size();
        for(int i=0;i<n;++i) {
            ans.push_back(ans[i]);
            ans.back().push_back(c);
        }
    }
    return ans;
}

Approach 3: bit manipulation

Note** How to check if kth bit is set or not for number n
=> n&&(1<<k) == 1 -> kth bit is set
-> 1<<2 means => 100

-> Iterate from 0 to 2^n =>#of subsets
-> for each value create a vector with values of elements on index , whose bits are set values 

=> Time O(n*2^n) & space O(1)

CODE:
vector<vector<int>> subsets(vector<int>& A) {
    vector<vector<int>> ans;
    int n=A.size();
    for(int num=0;num < (1<<n);++num) {
      vector<int> v;
      for(int j=0; j < n; ++j) {
        if(num & (1<<j)) {
          v.push_back(A[j]);
        }
      }
      ans.push_back(v);
    }
    return ans;
}