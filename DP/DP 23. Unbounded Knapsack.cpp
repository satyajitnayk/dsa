Approach 1: Recursion

#CODE:
int f(int i,int W,vector<int> &profit, vector<int> &wt) {
    if(i == 0) {
        return ((int)(W/wt[0])*profit[0]);
    }
    int nottake = f(i-1,W,profit,wt);
    int take = 0;
    if(wt[i] <= W) {
        take = profit[i] + f(i,W-wt[i],profit,wt);
    }
    return max(take, nottake);
}
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt)
{
    return f(n-1,W,profit,wt);
}
=> Time Complexity = Exponential (>> O(2^n))
=> Space Complexity = O(W)

Approach 2: Memoization

#CODE:
int f(int i,int W,vector<int> &profit, vector<int> &wt,vector<vector<int>> dp) {
    if(i == 0) {
        return ((int)(W/wt[0])*profit[0]);
    }
    if(dp[i][W] != -1) return dp[i][W];
    int nottake = f(i-1,W,profit,wt,dp);
    int take = 0;
    if(wt[i] <= W) {
        take = profit[i] + f(i,W-wt[i],profit,wt,dp);
    }
    return dp[i][W] = max(take, nottake);
}
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt)
{
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return f(n-1,W,profit,wt,dp);
}
=> Time Complexity = O(n*W)
=> Space Complexity = O(W) + O(n*W)

Approach 3: Tabulation

#CODE
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt)
{
    vector<vector<int>> dp(n,vector<int>(W+1,0));
    for(int i=0;i<=W;++i) {
        dp[0][i] = (i/wt[0])*profit[0];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=W;++j) {
            int nottake = dp[i-1][j];
            int take = 0;
            if(wt[i] <= j) {
                take = profit[i] + dp[i][j-wt[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n-1][W];
}
=> Time Complexity = O(n*W)
=> Space Complexity = O(n*W)

Approach 4: Space Optimization

#CODE:
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt)
{
    vector<int> prev(W+1,0), curr(W+1,0);
    for(int i=0;i<=W;++i) {
        prev[i] = (i/wt[0])*profit[0];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=W;++j) {
            int nottake = prev[j];
            int take = 0;
            if(wt[i] <= j) {
                take = profit[i] + curr[j-wt[i]];
            }
            curr[j] = max(take, nottake);
        }
        prev = curr;
    }
    return prev[W];
}
=> Time Complexity = O(n*W)
=> Space Complexity = O(2*W)

Approach 5: Further Space Optimization

#CODE:
int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &wt)
{
    vector<int> prev(W+1,0);
    for(int i=0;i<=W;++i) {
        prev[i] = (i/wt[0])*profit[0];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=W;++j) {
            int nottake = prev[j];
            int take = 0;
            if(wt[i] <= j) {
                take = profit[i] + prev[j-wt[i]];
            }
            prev[j] = max(take, nottake);
        }
    }
    return prev[W];
}
=> Time Complexity = O(n*W)
=> Space Complexity = O(W)