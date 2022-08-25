Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, 
and the combinations may be returned in any order.

Approach 1:
1. problem reduced to subset sum n of size k
2. Follwo subset 2 approach, but with few constarints.

##CODE:

void solve(vector<int> &A,int i,int k,int n,vector<int> &ss,vector<vector<int>> &ans)     {
    //BC
    if(k==0 && n==0){
        ans.push_back(ss);
        return;
    }
    if(A.size()-i+1<k || i >= A.size()) return;
    
    // solve subproblem
    if(k>0 && A[i] <= n) {
        ss.push_back(A[i]);
        solve(A,i+1,k-1,n-A[i],ss,ans);
        ss.pop_back();
    }
    solve(A,i+1,k,n,ss,ans);
    
}
vector<vector<int>> combinationSum3(int k, int n) {
    // problem reduced to subset sum n of size k
    // using numbers from 1-9
    vector<int> A = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    vector<int> ss;
    solve(A,0,k,n,ss,ans);
    return ans;
}