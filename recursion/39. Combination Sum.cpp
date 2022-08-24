Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers 
sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is 
less than 150 combinations for the given input.

## CODE:

void solve(vector<int> A,int target,int i,vector<int> &ss,vector<vector<int>> &ans) {
    // BC
    if(target==0){
        ans.push_back(ss);
        return;
    }
    if(target<0 || i >= A.size()) return;
    // ignore ith element
    solve(A, target,i+1,ss,ans);
    // include ith element
    ss.push_back(A[i]);
    solve(A,target-A[i],i,ss,ans);
    ss.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& A, int target) {
    vector<int> ss;
    vector<vector<int>> ans;
    solve(A,target,0,ss,ans);
    return ans;
}