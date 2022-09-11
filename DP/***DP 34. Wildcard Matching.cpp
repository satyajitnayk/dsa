Approach:
* matches any no of chars including ""(empty) char
? matxhes 1 char

Approach 1: Recursion

#CODE:
bool f(int i, int j,string &s, string &pattern) {
    if(i<0 && j<0) return true;
    if(j<0 && i>=0) return false;
    // is t chars left => if all * then true else false
    if(i<0 && j>=0) {
        for(int k=0;k<=j;++k) {
            if(pattern[k] != '*') return false;
        }
        return true;
    }
    if(pattern[j] == s[i] || pattern[j] == '?') {
        return f(i-1,j-1,s,pattern);
    } else if(pattern[j] == '*') {
        // consider comapring * and ""(empty char)
        bool op1 = f(i,j-1,s,pattern);
        // consider comparing 1 char
        bool op2 = f(i-1,j,s,pattern);
        return op1 | op2;
    } else return false;
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    return f(n-1,m-1,s,p);
}
=> Time complexity = Exponential
=> Space Complexity = O(n+m)

Approach 2: Memoization

#CODE:

bool f(int i, int j,string &s, string &pattern,vector<vector<int>> &dp) {
    if(i<0 && j<0) return true;
    if(j<0 && i>=0) return false;
    // is t chars left => if all * then true else false
    if(i<0 && j>=0) {
        for(int k=0;k<=j;++k) {
            if(pattern[k] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(pattern[j] == s[i] || pattern[j] == '?') {
        return dp[i][j] = f(i-1,j-1,s,pattern,dp);
    } else if(pattern[j] == '*') {
        // consider comapring * and ""(empty char)
        bool op1 = f(i,j-1,s,pattern,dp);
        // consider comparing 1 char
        bool op2 = f(i-1,j,s,pattern,dp);
        return dp[i][j] = op1 | op2;
    } else return dp[i][j] = false;
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,p,dp);
}
=> Time complexity = O(n*m)
=> Space Complexity = O(n+m) + O(n*m)

Approach 3: Memoization with 1 based indexing => for converting to tabulation

#CODE:
bool f(int i, int j,string &s, string &pattern,vector<vector<int>> &dp) {
    if(i==0 && j==0) return true;
    if(j==0 && i>0) return false;
    // is t chars left => if all * then true else false
    if(i==0 && j>0) {
        for(int k=1;k<=j;++k) {
            if(pattern[k-1] != '*') return false;
        }
        return true;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(pattern[j-1] == s[i-1] || pattern[j-1] == '?') {
        return dp[i][j] = f(i-1,j-1,s,pattern,dp);
    } else if(pattern[j-1] == '*') {
        // consider comapring * and ""(empty char)
        bool op1 = f(i,j-1,s,pattern,dp);
        // consider comparing 1 char
        bool op2 = f(i-1,j,s,pattern,dp);
        return dp[i][j] = op1 | op2;
    } else return dp[i][j] = false;
}
bool isMatch(string s, string pattern) {
    int n = s.size();
    int m = pattern.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
    return f(n,m,s,pattern,dp);
}

Approach 4: Tabulation

#CODE
bool isMatch(string s, string pattern) {
    int n = s.size();
    int m = pattern.size();
    vector<vector<bool>> dp(n+1,vector<bool>(m+1, false));
    dp[0][0] = true;
    for(int i=1;i<=n;++i) dp[i][0] = false;
    for(int j=1;j<=m;++j) {
        bool flag = true;
        for(int k=1;k<=j;++k) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(pattern[j-1] == s[i-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if(pattern[j-1] == '*') {
                dp[i][j] = dp[i][j-1] | dp[i-1][j];
            } else dp[i][j] = false;
        }
    }
    return dp[n][m];
}
=> Time complexity = O(n*m)
=> Space Complexity = O(n*m)

Approach 5: Space Optimization

#CODE:
bool isMatch(string s, string pattern) {
    int n = s.size();
    int m = pattern.size();
    vector<bool> prev(m+1, false), curr(m+1, false);
    prev[0] = curr[0] = true;
    for(int i=1;i<=n;++i) curr[0] = false;
    for(int j=1;j<=m;++j) {
        bool flag = true;
        for(int k=1;k<=j;++k) {
            if(pattern[k-1] != '*') {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(pattern[j-1] == s[i-1] || pattern[j-1] == '?') {
                curr[j] = prev[j-1];
            } else if(pattern[j-1] == '*') {
                curr[j] = curr[j-1] | prev[j];
            } else curr[j] = false;
        }
        prev = curr;
    }
    return prev[m];
}
=> Time complexity = O(n*m)
=> Space Complexity = O(2*m)