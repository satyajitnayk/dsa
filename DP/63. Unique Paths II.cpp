Approach 1: Recursion
int f(i,j) {
  // cell is blocked
  if(i>=0 && j >=0 && grid[i][j] == 1) return 0;
  if(i==0 && j==0)  return 1;
  if(i<0 || j<0) return 0;
  return f(i,j-1) + f(i-1,j);
} 
=> Time Complexity = O(2^mn)
=> Space Complexity = O(m+n)

Approach 2: Memoization

#CODE:
int f(int i,int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  // cell is blocked
  if(i>=0 && j >=0 && grid[i][j] == 1) return 0;
  if(i==0 && j==0)  return 1;
  if(i<0 || j<0) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = f(i,j-1,grid,dp) + f(i-1,j,grid,dp);
} 
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}
=> Time Complexity = O(mn)
=> Space Complexity = O(m+n) + O(mn)

Approach 3: Tabulation

#CODE:
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i>=0 && j >=0 && grid[i][j] == 1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1; 
            else {
                int up=0, left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }   
    return dp[n-1][m-1];
}
=> Time Complexity = O(mn)
=> Space Complexity = O(mn)

Approach 4: Space Optimization

#CODE:
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;++i) {
        vector<int> curr(m,0);
        for(int j=0;j<m;++j) {
            if(grid[i][j] == 1) curr[j] = 0;
            else if(i==0 && j==0) curr[j] = 1; 
            else {
                int up=0, left=0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }   
    return prev[m-1];
}
=> Time Complexity = O(mn)
=> Space Complexity = O(2*m)