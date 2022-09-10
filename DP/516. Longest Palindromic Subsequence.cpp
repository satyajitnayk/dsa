** Get LCS b/w s & reverse of s

Approach 1: Recursion

Approach 2: Memoization

Approach 3: Tabulation

#CODE:
int longestPalindromeSubseq(string s) {
    int n = s.size();
    string t = s;
    reverse(s.begin(),s.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n^2)

Approach 4: Space Optimization

#CODE:
int longestPalindromeSubseq(string s) {
    int n = s.size();
    string t = s;
    reverse(s.begin(),s.end());
    vector<int> prev(n+1,0), curr(n+1,0);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[n];
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(2*n)