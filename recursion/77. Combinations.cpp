Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.

Approach 1:
1. Follow subset method but with subset size k.

void solve(int num, int k,int n, vector<int> &ss, vector<vector<int>> &ans) {
    // BC
    if(ss.size() == k) {
        ans.push_back(ss);
        return;
    }
    if(num > n) return;
    
    ss.push_back(num);
    solve(num+1,k,n,ss,ans);
    ss.pop_back();
    solve(num+1,k,n,ss,ans);
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> ss;
    solve(1,k,n,ss,ans);
    return ans;
}

Approach 2:
1. Optimizing no of recursive calls.
2. After selecting ith elemnt we can reduce k value & so we have to chnage the base condition.
3. if num > n or there are less elements remaining than size of subset k.
void solve(int num, int k,int n, vector<int> &ss, vector<vector<int>> &ans) {
    // BC
    if(k==0){
        ans.push_back(ss);
        return;
    }
    // if num > n or there are less elements remaining than size of subset discard/return
    if(num>n || n-num+1<k)return
    ss.push_back(num);
    solve(num+1,k-1,n,ss,ans);
    ss.pop_back();
    solve(num+1,k,n,ss,ans);
}