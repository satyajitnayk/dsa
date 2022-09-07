Approach 1: Recursion

=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int mod = (int)(1e9 + 7);
int f(int i,int target,vector<int> &A,vector<vector<int>> &dp) {
  if(i == 0) {
      if(target == 0 && A[0] == 0) return 2;
      if(target == 0 || target == A[0]) return 1;
      return 0;
  }
  if(dp[i][target] != -1) return dp[i][target];
  int notpick = f(i-1,target,A,dp);
  int pick = 0;
  if(target >= A[i]) pick = f(i-1,target-A[i],A,dp);
  return dp[i][target] = (pick + notpick) % mod;
}
int countPartitions(int n, int d, vector<int> &A) {
    int sum=0;
    for(auto &it:A) sum += it;
    int target = (sum-d)/2;
    if(sum-d < 0 || (sum-d) % 2) return 0;
    // target is subset sum => sum-d >= 0
    // sum is even as sum is subset sum
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,A,dp);
}

=> Time Complexity = O(n*target)
=> Space Complexity = O(n) + O(n*target)

Approach 3: Tabulation

#CODE:
int mod = (int)(1e9 + 7);
int countPartitions(int n, int d, vector<int> &A) {
    int sum=0;
    for(auto &it:A) sum += it;
    int target = (sum-d)/2;
    if(sum-d < 0 || (sum-d) % 2) return 0;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(A[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(A[0] != 0 && A[0] <= target) dp[0][A[0]] = 1;
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
          int notpick = dp[i-1][j];
          int pick = 0;
          if(j >= A[i]) pick = dp[i-1][j-A[i]];
          dp[i][j] = (pick + notpick) % mod;
        }
    }
    return dp[n-1][target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target)

Approach 4: Space Optimization

#CODE:
int mod = (int)(1e9 + 7);
int countPartitions(int n, int d, vector<int> &A) {
    int sum=0;
    for(auto &it:A) sum += it;
    int target = (sum-d)/2;
    if(sum-d < 0 || (sum-d) % 2) return 0;
    vector<int> prev(target+1,0);
    if(A[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(A[0] != 0 && A[0] <= target) prev[A[0]] = 1;
    for(int i=1;i<n;++i) {
        vector<int> curr(target+1,0);
        for(int j=0;j<=target;++j) {
          int notpick = prev[j];
          int pick = 0;
          if(j >= A[i]) pick = prev[j-A[i]];
          curr[j] = (pick + notpick) % mod;
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(target)


