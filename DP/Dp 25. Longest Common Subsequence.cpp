f(i,j) => length of longest common subsequence b/w string s1[0...i] & s2[0....j]
*Note: match OR not match

Approach 1: Recursion

#CODE:
int f(int i,int j,string &s1,string &s2) {
 if(i<0 || j<0) return 0;
    if(s1[i] == s2[j]) return 1 + f(i-1,j-1,s1,s2);
    int op1 = f(i-1,j,s1,s2);
    int op2 = f(i,j-1,s1,s2);
    return max(op1,op2);
}
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    return f(n-1,m-1,s1,s2);
}
=> Time Complexity = Exponential = O(2^n*2*m)
=> **Space Complexity = O(n+m)

Approach 2: Memoization

#CODE:
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp) {
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp);
    int op1 = f(i-1,j,s1,s2,dp);
    int op2 = f(i,j-1,s1,s2,dp);
    return dp[i][j] = max(op1,op2);
}
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s1,s2,dp);
}
=> Time Complexity = O(n*m)
=> **Space Complexity = O(n+m) + O(n*m)

Approach 3: Tabulation

#CODE1:
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(s1[i] == s2[j]) dp[i][j] = 1 + ((i>0 && j>0) ? dp[i-1][j-1] : 0);
            else {
                int op1 = (i>0 ? dp[i-1][j] : 0);
                int op2 = (j>0 ? dp[i][j-1] : 0);
                dp[i][j] = max(op1, op2);
            }
        }
    }
    return dp[n-1][m-1];
}
=> Time Complexity = O(n*m)
=> Space Complexity = O(n*m)

Approach 4: Tabulation with index shifting to handle the base cases.
i.e. f(i,j) => compare s1[i-1] & s2[j-1]

int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }
    return dp[n][m];
}

Approach 5: Space Optimization

#CODE:
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0), curr(m+1,0); 
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else  curr[j] = max(prev[j], curr[j-1]);
        }
        prev = curr;
    }
    return prev[m];
}
=> Time Complexity = O(n*m)
=> Space Complexity = O(2*m)