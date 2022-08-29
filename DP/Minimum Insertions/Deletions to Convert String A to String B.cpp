Approach:
1. Which charcters I can not touch? => to minimize cost.
2. #of deletions = n - length(Longest Common Subsequence)
3. #of insertion = m - length(Longest Common Subsequence)
4. Ans = #of insertion + #of deletions

##CODE:

int lcs(string &s,string &t) {
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i <= n; ++i) {
        for(int j=1; j <= m; ++j) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int lcsLen = lcs(str,ptr);
    int n = str.size();
    int m = ptr.size();
    return n+m-2*lcsLen;
}
=> Time O(n*m) & space O(n*m)