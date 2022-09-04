Approach 1: Recursion

*f(i,j) => miniimum cost to travel from (0,0) to (i,j)
f(i,j) {
  if(i==0 && j==0) return grid[0][0];
  if(i<0 || j<0) return INT_MAX; // not to cosider this path
  int up = grid[i][j] + f(i,j-1);
  int left = grid[i][j] + f(i-1,j);
  return min(up, left);
}
=> Time Complexity = O(2^mn)
=> Space Complexity = O(mn)

Approach 2: Memoization

#CODE:

int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp) {
    if(i==0 && j==0) return grid[0][0];
    else if(i<0 || j<0) return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    int left = left = f(i,j-1, grid,dp);
    int up =  up = f(i-1,j,grid,dp);
    return dp[i][j] = grid[i][j] + min(up, left);
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,grid, dp);
}

=> Time Complexity = O(mn)
=> Space Complexity = O(mn) + O(path length = O(n-1+m-1))

Approach 3: Tabulation

#CODE:
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else  {
                int left = (j>0 ? dp[i][j-1] : INT_MAX);
                int up =  (i>0 ? dp[i-1][j] : INT_MAX);
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}
=> Time Complexity = O(mn)
=> Space Complexity = O(m*n)

Approach 4: Space Optimization

#CODE:
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,INT_MAX);
    for(int i=0;i<n;++i) {
        vector<int> curr(m,0);
        for(int j=0;j<m;++j) {
            if(i==0 && j==0) curr[j] = grid[i][j];
            else  {
                int left = (j>0 ? curr[j-1] : INT_MAX);
                int up =  (i>0 ? prev[j] : INT_MAX);
                curr[j] = grid[i][j] + min(left, up);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
=> Time Complexity = O(mn)
=> Space Complexity = O(2*m)
