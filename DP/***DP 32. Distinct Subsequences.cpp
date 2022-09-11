Approach:**For any number of ways problem we follow recursion pattern;
f() {
  BASE CASE

  return f()+f()+..... [All possible ways]

}

##Approach 1:

1. Express everything in terms of (i,j).
  a. i means substring 0....i ,same for j
2. Explore all possibilities.
3. Return summation of all possibilities.
4. Base Case.

int solve(int i,int j) {
  //BC
  // Maintain ORDER OF CHECKING j -> i
    // All chars of t matches
  if(j < 0) return 1;
  // s is exhausted but t is not => return 0
  if(i < 0) return 0;

  if(s[i] == t[j]) {
    // 2 ways either compare or skip
    return solve(i-1,j-1) + solve(i-1,j);
  } else{
    // 1 way skip
    return solve(i-1,j);
  }
}
=> Time complexity = O(2^mn) => exponential
=> Space complexity = O(m+n)


##Approach 2:

**We could optimize this problem as there are overlapping subproblem, we could memoize dp[n][m]

int f(int i,int j, string &s, string &t, vector<vector<int>> &dp) {
    if(j < 0) return 1;
    if(i < 0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) {
        return dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1, j,s,t,dp);
    } else {
        return dp[i][j] = f(i-1, j, s, t, dp);
    }

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    return f(n-1, m-1, s, t,dp);
}
=> Time complexity = O(n*m)
=> Space complexity = O(n+m) + O(n*m) // size of dp


##Approach 3: Tabulation Approach

**General steps to build tabulation solution:
1. Declare dp of same size as memoization.
2. Write down the base cases.
3. Write down the change in parameters in opposite fashion.
4. Copy paste the recusrion steps from memoization. 


=> For this question, as there is possibility of i,j < 0 so we can add +1 to i,j initially
=> i.e. return f(n, m, s, t,dp); initially & change base cases.

i == 0 => string of size 0. same for j == 0

#CODE:

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    
    // we can always find empty subsequence in a string
    for(int i=0;i<=n;++i) dp[i][0] = 1; 
    // skip dp[0][0]
    // we can not find any subsequence in an empty string
    // for(int j=1;j<=m;++j) dp[0][j] = 0;
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        if(s[i-1] == t[j-1]) {
          dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        } else {
          dp[i][j] = dp[i-1][j];
        }
      }
    }
    return (int)dp[n][m];
}
=> Time complexity = O(n*m)
=> Space complexity = O(n*m)

##Approach 4: We coould optimize space.

=> As we can see from code we just need to store previous & current state => i.e. dp[i-1][j-1], dp[i-1][j] 

#CODE:

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1, 0), curr(m+1, 0);
    prev[0] = curr[0] = 1
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=m; ++j) {
        if(s[i-1] == t[j-1]) {
          curr[j] = prev[j-1] + prev[j];
        } else {
          curr[j] = prev[j];
        }
      }
      prev = curr;
    }
    return (int)prev[m];
}
=> Time O(n*m)
=> Space O(2*m)

##Approach 5: We could optimize space to O(m) from O(2*m)

#CODE:

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1, 0);
    prev[0] = 1
    for(int i=1; i<=n; ++i) {
      for(int j=m; j>=1; --j) {
        if(s[i-1] == t[j-1]) {
          prev[j] = prev[j-1] + prev[j];
        }
      }
        
    }
    return (int)prev[m];
}