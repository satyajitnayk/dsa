f(i,j) => no of unique ways we can reach from (0,0) to (i,j)

Approach 1: Recursion

int f(i,j) {
  if(i==0 && j==0)  return 1;
  if(i<0 || j<0) return 0;
  return f(i,j-1) + f(i-1,j);
} 
=> Time O(2^mn) & Space O(m+n)

Approach 2: Memoization

#code
int f(int i,int j, vector<vector<int>> &dp) {
  if(i==0 && j==0)  return 1;
  if(i<0 || j<0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = f(i,j-1,dp) + f(i-1,j,dp);
} 
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,-1));
    return f(m-1,n-1,dp);
}
=> Time O(n*m) & Space = O(m*n) + O(m+n)

Approach 3: Tabulation

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n,0));
    for(int i=0;i<m;++i) {
        for(int j=0;j<n;++j) {
            if(i==0 && j==0) dp[i][j] = 1;
            else {
                int up = i>0 ? dp[i-1][j] : 0;
                int left = j>0 ? dp[i][j-1] : 0;
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m-1][n-1];
}
=> Time O(n*m) & Space = O(n*m)

Approach 4: Space Optimization


#CODE:
int uniquePaths(int m, int n) {
      vector<int> prev(n,0);
    for(int i=0;i<m;++i) {
          vector<int> curr(n,0);
        for(int j=0;j<n;++j) {
              if(i==0 && j==0) curr[j] = 1;
            else {
                  int up = 0, left=0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

=> Time O(n*m) & Space = O(2*n)

Approach 5: Time Optimization : Combination

1. Tital directions => m+n-2
2. We need to place m-1 bottom moves OR n-1 right moves.
3. ans = (m+n-2)C(m-1) OR ans = (m+n-2)C(n-1)

#CODE
int uniquePaths(int m, int n) {
    int N = n+m-2;
    int r = m-1;
    double res = 1;
    for(int i=1;i<=r;++i) {
        res = res * (N-r+i) / i;
    }
    return (int)res;
}
=> Time Complexity = O(n-1) OR O(m-1)
=> Space Complexity = O(1)

