Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Approach 1:
1. Similar to subset II priblem.
2. sort all elementt in vector A.
3. Once a number ignored, ignore it in all future occurences.

## CODE:

void solve(vector<int>& A,int target,int i,vector<int> &ss,vector<vector<int>> &ans){
  // BC
    if(target==0) {
        ans.push_back(ss);
        return;
    }
    if(i>=A.size() || target < 0) return;
    
    // Little optimization // if target is smaller that ith elemnt discard the recursion path there.
    if(target >= A[i]) {
        ss.push_back(A[i]);
        solve(A,target-A[i],i+1,ss,ans);
        ss.pop_back();
    }
    while(i+1<A.size() && A[i]==A[i+1]) i++;
    solve(A,target,i+1,ss,ans);
}
vector<vector<int>> combinationSum2(vector<int>& A, int target) {
    // sort A
    sort(A.begin(), A.end());
    vector<int> ss;
    vector<vector<int>> ans;
    solve(A,target,0,ss,ans);
    return ans;
}