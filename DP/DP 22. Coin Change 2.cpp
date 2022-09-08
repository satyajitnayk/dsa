Approach 1: Recursion

#CODE:
int f(int i, int target, vector<int>& coins) {
    if(i==0) {
        if(target%coins[0] == 0) return 1;
        return 0;
    }
    int nottake = f(i-1,target,coins);
    int take = 0;
    if(coins[i] <= target) take = f(i,target-coins[i],coins);
    return take + nottake;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    return f(n-1,amount,coins);
}
=> Time Complexity = Exponential (as >> O(2^n))
=> Space Complexity = O(target) (consider coin is 1 so tree depth target/1)

Approach 2: Memoization

#CODE:
int f(int i, int target, vector<int>& coins,vector<vector<int>> &dp) {
    if(i==0) {
        if(target%coins[0] == 0) return 1;
        return 0;
    }
    if(dp[i][target] != -1) return dp[i][target];
    int nottake = f(i-1,target,coins,dp);
    int take = 0;
    if(coins[i] <= target) take = f(i,target-coins[i],coins,dp);
    return dp[i][target] = take + nottake;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int target = amount;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,amount,coins,dp);
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(target) + O(n*target)

Approach 3:Tabulation

#CODE:
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int target = amount;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<=target;++i) {
        if(i % coins[0] == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
            int nottake = dp[i-1][j];
            int take = 0;
            if(coins[i] <= j) take = dp[i][j-coins[i]];
            dp[i][j] = take + nottake;
        }
    }
    return dp[n-1][target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(n*target)

Approach 4: Space Optimization

#CODE:
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int target = amount;
    vector<int> prev(target+1,0), curr(target+1,0);
    for(int i=0;i<=target;++i) {
        if(i % coins[0] == 0) prev[i] = 1;
        else prev[i] = 0;
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
            int nottake = prev[j];
            int take = 0;
            if(coins[i] <= j) take = curr[j-coins[i]];
            curr[j] = take + nottake;
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(2*target)