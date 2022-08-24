Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Approach 1:
1. Sort all elements in A, so that all same elemnt are consecutive.
1. At each recursive step if I have ignore any element then I will ignore it in all future occurences.

##CODE:

void solve(vector<int>& A, int idx, vector<int> &ss, vector<vector<int>> &ans) {
    // BC
    if(idx == A.size()) {
        ans.push_back(ss);
        return;
    }
    ss.push_back(A[idx]);
    solve(A,idx+1,ss,ans);
    ss.pop_back();
    // ignore the A[idx] element in all future occurences
    while(idx+1<A.size() && A[idx]==A[idx+1]) idx++;
    solve(A,idx+1,ss,ans);
}
vector<vector<int>> subsetsWithDup(vector<int>& A) {
    // sort all elements in A, so that all same elemnt are consecutive
    sort(A.begin(),A.end());
    vector<int> ss;
    vector<vector<int>> ans;
    solve(A,0,ss,ans);
    return ans;
}

