Approach 1: Recursion

#CODE:
int f(int i, int j,vector<int> &cuts) {
    if(i > j) return 0;
    int mini = INT_MAX;
    for(int k=i;k<=j;++k) {
        int cost = cuts[j+1] - cuts[i-1]  + f(i,k-1,cuts) + f(k+1,j,cuts);
        mini = min(mini, cost);
    }
    return mini;
}
int minCost(int n, vector<int>& cuts) {
    int m = cuts.size();
    cuts.push_back(n);
    cuts.push_back(0);
    // sort to solve sub problems independently
    sort(cuts.begin(), cuts.end());
    return f(1,m,cuts);
}
=> Time Complexity = Exponential
=> Space Complexity = O(m)

Approach 2: Memoization

#CODE:
int f(int i, int j,vector<int> &cuts,vector<vector<int>> &dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = INT_MAX;
    for(int k=i;k<=j;++k) {
        int cost = cuts[j+1] - cuts[i-1]  + f(i,k-1,cuts,dp) + f(k+1,j,cuts,dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int>& cuts) {
    int m = cuts.size();
    cuts.push_back(n);
    cuts.push_back(0);
    // sort to solve sub problems independently
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    return f(1,m,cuts,dp);
}
=> Time Complexity = O(m^3)
=> Space Complexity = O(m) + O(m^2)

Approach 3: Tabulation

#CODE:
int minCost(int n, vector<int>& cuts) {
    int m = cuts.size();
    cuts.push_back(n);
    cuts.push_back(0);
    // sort to solve sub problems independently
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(m+2,vector<int>(m+2,0));
    for(int i=m;i>=1;--i) {
        for(int j=1;j<=m;++j) {
            if(i>j) continue;
            int mini = INT_MAX;
            for(int k=i;k<=j;++k) {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][m];
}
=> Time Complexity = O(m^3)
=> Space Complexity = O(m^2)