
Approach 1: Recursion : DP on Subsequences
1. Generate all subsequences & if any of them gives sum k
2. Express in terms of (ind, target)
3. Explore possibilities of that index.(i.e. Either choose A[ind] or skip A[ind])
4. Return 0/1

f(i,target) => #of subsequences from index 0 to i whose sum = target

bool f(int i,int target, vector<int> &A) {
  if(target == 0) return true;
  if(i==0) return A[i] == target;
  bool op1 = f(i-1,target,A);
  bool op2 = false;
  if(A[i] <= target) op2 = f(i-1,target-A[i],A);
  return op1 || op2;
}
int solve(vector<int> &A, int B) {
    int n = A.size();
    return f(n-1,B,A) ? 1 : 0;
}

=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
bool f(int i,int target, vector<int> &A,vector<vector<int>> &dp) {
  if(target == 0) return true;
  if(i==0) return A[i] == target;
  if(dp[i][target] != -1) return dp[i][target];
  bool op1 = f(i-1,target,A,dp);
  bool op2 = false;
  if(A[i] <= target) op2 = f(i-1,target-A[i],A,dp);
  return dp[i][target] = op1 | op2;
}
int solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(B+1,-1));
    return f(n-1,B,A,dp);
}

=> Time Complexity = O(target*n)
=> Space Complexity = O(target*n) + O(n)

Approach 3: Tabulation

#CODE:
bool solve(vector<int> &A, int target) {
    int n = A.size();
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    dp[0][A[0]] = true;
    for(int i=0;i<n;++i) dp[i][0] = true;
    for(int i=1;i<n;++i) {
        for(int j=1;j<=target;++j) {
            bool op1 = dp[i-1][j];
            bool op2 = false;
            if(A[i] <= j) op2 = dp[i-1][j-A[i]];
            dp[i][j] = op1 | op2;
        } 
    }
    return dp[n-1][target];
}
=> Time Complexity = O(target*n)
=> Space Complexity = O(target*n)

Approach 4: Space Optimization

#CODE:
bool solve(vector<int> &A, int target) {
    int n = A.size();
    vector<bool> prev(target+1,false), curr(target+1,false);
    prev[0] = curr[0] = true;
    // void overflow
    if(A[0] <= target) prev[A[0]] = true;
    for(int i=1;i<n;++i) {
        curr[0] = true;
        for(int j=1;j<=target;++j) {
            bool op1 = prev[j];
            bool op2 = false;
            if(A[i] <= j) op2 = prev[j-A[i]];
            curr[j] = op1 | op2;
        } 
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(target*n)
=> Space Complexity = O(target)