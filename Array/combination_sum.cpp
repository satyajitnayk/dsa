Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum
 to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations 
are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than
150 combinations for the given input.


vector<vector<int>> ans;
void solve(vector<int> A, int target, int idx,vector<int> q) {
    if(target == 0) {
        ans.push_back(q);
        return;
    }
    if(target < 0 || idx == A.size()) return;
    
    solve(A,target,idx+1,q);
    
    q.push_back(A[idx]);
    solve(A,target-A[idx],idx,q);
    q.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& A, int target) {
    vector<int> q;
    solve(A,target,0,q);
    return ans;
}

