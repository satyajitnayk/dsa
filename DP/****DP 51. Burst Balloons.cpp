**NOTE:
1. We can not solve sub problems individually, as sub problems depends on each others values.
2. So we could solve it in reverse order of recursion.
 i.e. Collect the coins for the ballon first which will burst last.

 [... a b c d e ...]
      i   k   j
=> If kth element (c) is the last ballon to burst then coin collected = A[i-1] * A[k] * A[j+1]
 
Approach 1: Recursion

#CODE:
int f(int i,int j,vector<int> &A) {
    if(i > j) return 0;
    int maxi = INT_MIN;
    for(int k=i;k<=j;++k) {
        int coins = A[i-1] * A[k] * A[j+1] + f(i,k-1,A) + f(k+1,j,A);
        maxi = max(maxi, coins);
    }
    return maxi;
}
int maxCoins(vector<int>& A) {
    int n = A.size();
    A.push_back(1);
    A.insert(A.begin(),1);
    return f(1,n,A);
}
=> Time Complexity = Exponential
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i,int j,vector<int> &A,vector<vector<int>> &dp) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = INT_MIN;
    for(int k=i;k<=j;++k) {
        int coins = A[i-1] * A[k] * A[j+1] + f(i,k-1,A,dp) + f(k+1,j,A,dp);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}
int maxCoins(vector<int>& A) {
    int n = A.size();
    A.push_back(1);
    A.insert(A.begin(),1);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(1,n,A,dp);
}
=> Time Complexity = O(n^3)
=> Space Complexity = O(n) + O(n^2)

Approach 3: Tabulation

#CODE:
int maxCoins(vector<int>& A) {
    int n = A.size();
    A.push_back(1);
    A.insert(A.begin(),1);
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    for(int i=n;i>=1;--i) {
        for(int j=1;j<=n;++j) {
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int k=i;k<=j;++k) {
                int coins = A[i-1] * A[k] * A[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}
=> Time Complexity = O(n^3)
=> Space Complexity = O(n^2)