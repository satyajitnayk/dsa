Approach 1: Recursion

#CODE:
int f(int i,int target,vector<int> &A) {
  if(target == 0) return 1;
  if(i == 0)   return A[0] == target;
  int notpick = f(i-1,target,A);
  int pick = 0;
  if(target >= A[i]) pick = f(i-1,target-A[i],A);
  return pick + notpick;
}
int findWays(vector<int> &A, int target)
{
    int n = A.size();
    return f(n-1, target, A);
}
=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i,int target,vector<int> &A,vector<vector<int>> &dp) {
  if(target == 0) return 1;
  if(i == 0) return A[0] == target;
  if(dp[i][target] != -1) return dp[i][target];
  int notpick = f(i-1,target,A,dp);
  int pick = 0;
  if(target >= A[i]) pick = f(i-1,target-A[i],A,dp);
  return dp[i][target] = pick + notpick;
}
int findWays(vector<int> &A, int target)
{
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1, target, A,dp);
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target) + O(n)

Approach 3: Tabulation

#CODE:
int findWays(vector<int> &A, int target)
{
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;++i) dp[i][0] = 1;
    if(A[0] <= target) dp[0][A[0]] = 1;
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
              int notpick = dp[i-1][j];
              int pick = 0;
              if(j >= A[i]) pick = dp[i-1][j-A[i]];
              dp[i][j] = pick + notpick;
        }
    }
    return dp[n-1][target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target)

Approach 4: Space Optimization

#CODE:
int findWays(vector<int> &A, int target)
{
    int n = A.size();
    vector<int> prev(target+1,0);
    for(int i=0;i<n;++i) prev[0] = 1;
    if(A[0] <= target) prev[A[0]] = 1;
    for(int i=1;i<n;++i) {
        vector<int> curr(target+1,0);
        for(int j=0;j<=target;++j) {
              int notpick = prev[j];
              int pick = 0;
              if(j >= A[i]) pick = prev[j-A[i]];
              curr[j] = pick + notpick;
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(target)