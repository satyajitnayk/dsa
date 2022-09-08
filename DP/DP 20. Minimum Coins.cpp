1. We can dirst think of greedy, but in some cases greedy will fail!
2. [1,5,6,9] 
target = 11
Greedy => 9+1+1
Actual => 6+5 => so we need to use Dynamic Programming

Approach 1: Recursion
f(i,target) => minimum no of coins to get target if coins from index 0 to i are allowed.

int f(int i,int target,vector<int> &A) {
  if(i==0) {
    if(target % A[0] == 0)  return target/A[0];
    else return 1e9;
  }
  int nottake = f(i-1,target,A);
  int take = 1e9;
  if(A[i] <= target) {
    take = 1 + f(i,target-A[i],A);
  }
  return min(nottake,take);
}
int minimumCoins(int target)
{
    vector<int> A = {1,2,5,10,20,50,100,500,1000};
    int n = A.size();
    return f(n-1,target,A);
}
=> Time Complexity >> O(2^n) = so call it Exponential
=> Space Complexity = O(target)

Approach 2: Memoization

#CODE:
int f(int i,int target,vector<int> &A,vector<vector<int>> &dp) {
  if(i==0) {
    if(target % A[0] == 0)  return target/A[0];
    else return 1e9;
  }
  if(dp[i][target] != -1) return dp[i][target];
  int nottake = f(i-1,target,A,dp);
  int take = 1e9;
  if(A[i] <= target) {
    take = 1 + f(i,target-A[i],A,dp);
  }
  return dp[i][target] = min(take,nottake);
}
int minimumCoins(int target)
{
    vector<int> A = {1,2,5,10,20,50,100,500,1000};
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,A,dp);
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target) + O(target)

Approach 3: Tabulation

#CODE:
int minimumCoins(int target)
{
    vector<int> A = {1,2,5,10,20,50,100,500,1000};
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(target+1,1e9));
    for(int t=0;t<=target;++t) {
        if(target%A[0] == 0) dp[0][t] = t/A[0];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
              int nottake = dp[i-1][j];
              int take = 1e9;
              if(A[i] <= j) {
                take = 1 + dp[i][j-A[i]];
              }
              dp[i][j] = min(take,nottake);
        }
    }
    return dp[n-1][target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target)

Approach 4: Space Optimization

#CODE:
int minimumCoins(int target)
{
    vector<int> A = {1,2,5,10,20,50,100,500,1000};
    int n = A.size();
    vector<int> prev(target+1,1e9), curr(target+1,1e9);
    for(int t=0;t<=target;++t) {
        if(target%A[0] == 0) prev[t] = t/A[0];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
              int nottake = prev[j];
              int take = 1e9;
              if(A[i] <= j) {
                take = 1 + curr[j-A[i]];
              }
              curr[j] = min(take,nottake);
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(2*target)