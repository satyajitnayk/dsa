**Approach:
1. Keep the longest palidrome portion intact.
2. Add reverse of non palidrome part.
=> Ans = Length Of String - longestPalindromeSubseqe of String

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
int minInsertions(string s) {
    return s.size() - longestPalindromeSubseq(s);
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
int minInsertions(string s) {
    return s.size() - longestPalindromeSubseq(s);
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(2*n)