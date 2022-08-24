Q.Return all subsets of an set/powerset.

Time Complexity => No of nodes in recursion tree = O(2^n)
Space Complexity => Height of recusrion tree = O(n)

Approach 1:

## CODE:
vector<vector<int>> solve(vector<int>& A, int i) {
    if(i>=A.size()) return {{}};//empty vector of vector
    // get all subsets from index i+1 till end
    vector<vector<int>> partialAns = solve(A, i+1);
    vector<vector<int>> ans;
    // create copy of partial subsets from index i+1 till end
    for(auto x:partialAns) ans.push_back(x);
    // append A[i] to each of the subsets copy & return the answer
    for(auto x:partialAns) {
        x.push_back(A[i]);
        ans.push_back(x);
    }
    return ans;
}
vector<vector<int>> subsets(vector<int>& A) {
    vector<vector<int>> ans = solve(A,0);
    return ans;
}


Approach 2:

##CODE:
void solve(vector<int>& A, int i,vector<int> &subset, vector<vector<int>> &ans) {
  //BC
  if(i==A.size()) {
    ss.push_back(subset);
    return;
  }
  //Include the ith element
  subset.push_back(A[i]);
  solve(A,i+1,subset,ans);
  //Donot include ith element
  subset.pop_back();
  solve(A,i+1,subset,ans);
}
vector<vector<int>> subsets(vector<int>& A) {
    vector<vector<int>> ans;
    vector<int> subset={};
    solve(A,0,subset,ans);
    return ans;
}