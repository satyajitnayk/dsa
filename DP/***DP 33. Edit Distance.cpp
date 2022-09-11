f(i,j) => min operations need to convert s[0...i] to t[0...j]

Approach 1: Recursion

#CODE:
int f(int i,int j,string &s1,string &s2) {
    if(j<0) return i+1;
    if(i<0) return j+1;
    if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2);
    else {
        // insert char in s
        int op1 = 1 + f(i,j-1,s1,s2);
        // delete char from s
        int op2 = 1 + f(i-1,j,s1,s2);
        // replace char in s
        int op3 = 1 + f(i-1,j-1,s1,s2);
        return min(op1, min(op2, op3));
    }
}
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    return f(n-1,m-1,s1,s2);
}
=> Time Complexity = O(3^mn) = Exponential
=> Space Complexity = O(m+n)

Approach 2: Memoization

#CODE
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp) {
    if(j<0) return i+1;
    if(i<0) return j+1;
    if( dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]) return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    else {
        // insert char in s
        int op1 = 1 + f(i,j-1,s1,s2,dp);
        // delete char from s
        int op2 = 1 + f(i-1,j,s1,s2,dp);
        // replace char in s
        int op3 = 1 + f(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min(op1, min(op2, op3));
    }
}
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s1,s2,dp);
}
=> Time Complexity = O(m*n)
=> Space Complexity = O(m+n) + O(m*n)

Approach 3: Converting to 1 based indexing from 0 based indexing for tabulation
#CODE:
int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp) {
    if(j==0) return i;
    if(i==0) return j;
    if( dp[i][j] != -1) return dp[i][j];
    if(s1[i-1] == s2[j-1]) return dp[i][j] = f(i-1,j-1,s1,s2,dp);
    else {
        // insert char in s
        int op1 = 1 + f(i,j-1,s1,s2,dp);
        // delete char from s
        int op2 = 1 + f(i-1,j,s1,s2,dp);
        // replace char in s
        int op3 = 1 + f(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min(op1, min(op2, op3));
    }
}

Approach 4: tabulation

#CODE:
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int j=0;j<=m;++j) dp[0][j] = j;
    for(int i=1;i<=n;++i) dp[i][0] = i;
    for(int i=1;i<=n;++i) {
      for(int j=1;j<=m;++j) {
        if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
        else {
            // insert char in s
            int op1 = 1 + dp[i][j-1];
            // delete char from s
            int op2 = 1 + dp[i-1][j];
            // replace char in s
            int op3 = 1 + dp[i-1][j-1];
            dp[i][j] = min(op1, min(op2, op3));
        }
          
      }
    }
    return dp[n][m];
}
=> Time Complexity = O(m*n)
=> Space Complexity = O(m*n)

Approach 5: Space Optimization

#CODE:
int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m+1,0), curr(m+1,0);
    for(int j=0;j<=m;++j) prev[j] = j;
    for(int i=1;i<=n;++i) {
        curr[0] = i;
        for(int j=1;j<=m;++j) {
            if(s1[i-1] == s2[j-1]) curr[j] = prev[j-1];
            else {
                // insert char in s
                int op1 = 1 + curr[j-1];
                // delete char from s
                int op2 = 1 + prev[j];
                // replace char in s
                int op3 = 1 + prev[j-1];
                curr[j] = min(op1, min(op2, op3));
            }
            
        }
        prev = curr;
    }
    return prev[m];
}
=> Time Complexity = O(m*n)
=> Space Complexity = O(2*m)