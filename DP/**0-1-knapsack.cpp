*Since the data are not uniform we can not apply greedy here, instead we will use Dynamic Programming.

**f(i,w) => Maximum profit gained if bag size is w & elements from index 0 to i are allowed.

Approach 1: Recursion

#CODE:
int f(int i,int W, vector<int> &A,vector<int> &wt) {
  if(i==0) {
    if(wt[0] <= W) return A[0];
    else return 0;
  }
  int notpick = f(i-1,W,A,wt);
  int pick = INT_MIN;
  if(wt[i] <= W) pick = A[i] + f(i-1,W-wt[i],A,wt);
  return max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(n-1,maxWeight,value,weight);
}
=> Time Complexity = O(2^n)
=> Space Complexity = O(n) 

Approach 2: Memoization

#CODE:
int f(int i,int W, vector<int> &A,vector<int> &wt,vector<vector<int>> &dp) {
  if(i==0) {
    if(wt[0] <= W) return A[0];
    else return 0;
  }
  if(dp[i][W] != -1) return dp[i][W];
  int notpick = f(i-1,W,A,wt,dp);
  int pick = INT_MIN;
  if(wt[i] <= W) pick = A[i] + f(i-1,W-wt[i],A,wt,dp);
  return dp[i][W] = max(pick, notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,value,weight,dp);
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n) +  O(n*target)

Approach 3: Tabulation

#CODE:
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=wt[0];i<=W;++i) dp[0][i] = val[0];
    for(int i=1;i<n;++i) {
        for(int j=0;j<=W;++j){
          int notpick = dp[i-1][j];
          int pick = INT_MIN;
          if(wt[i] <= j) pick = val[i] + dp[i-1][j-wt[i]];
          dp[i][j] = max(pick, notpick);
        }
    }
	return dp[n-1][W];
}

=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target)

Approach 4: Space Optimization

#CODE:
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
    vector<int> prev(W+1,0), curr(W+1,0);
    for(int i=wt[0];i<=W;++i) prev[i] = val[0];
    for(int i=1;i<n;++i) {
        for(int j=0;j<=W;++j){
          int notpick = prev[j];
          int pick = INT_MIN;
          if(wt[i] <= j) pick = val[i] + prev[j-wt[i]];
          curr[j] = max(pick, notpick);
        }
        prev = curr;
    }
	return prev[W];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(2*target)

Approach 5: Further Space Optimization

***Try to fill from Right -> Left (As current need previous data)

#CODE:
int knapsack(vector<int> wt, vector<int> val, int n, int W) 
{
    vector<int> prev(W+1,0);
    for(int i=wt[0];i<=W;++i) prev[i] = val[0];
    for(int i=1;i<n;++i) {
        for(int j=W;j>=0;--j){
          int notpick = prev[j];
          int pick = INT_MIN;
          if(wt[i] <= j) pick = val[i] + prev[j-wt[i]];
          prev[j] = max(pick, notpick);
        }
    }
    return prev[W];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(target)