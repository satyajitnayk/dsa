#Find Max path sum from any cell of first row to anycell of last row.

f(i,j) => maximum path sum from (0,j) to (n-1,j)

Approach 1: Recursion

#CODE:
int f(int i, int j, vector<vector<int>> &matrix) {
    if(j<0 || j>=matrix[0].size()) return -1e8; 
    if(i == 0) return matrix[0][j];
    int up = matrix[i][j] + f(i-1,j,matrix);
    int ld = matrix[i][j] + f(i-1,j-1,matrix);
    int rd = matrix[i][j] + f(i-1,j+1,matrix);
    return max(up,max(ld, rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxsum = -1e8;
    for(int j=0;j<m;++j) {
        maxsum = max(maxsum, f(n-1,j,matrix));
    }
    return maxsum;
}
// => Time Complexity = O(3^n)
// => Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp) {
    if(j<0 || j>=matrix[0].size()) return -1e8; 
    if(i == 0) return matrix[0][j];
    if(dp[i][j] != -1) return dp[i][j];
    int up = matrix[i][j] + f(i-1,j,matrix,dp);
    int ld = matrix[i][j] + f(i-1,j-1,matrix,dp);
    int rd = matrix[i][j] + f(i-1,j+1,matrix,dp);
    return dp[i][j] = max(up,max(ld, rd));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int maxsum = -1e8;
    for(int j=0;j<m;++j) {
        maxsum = max(maxsum, f(n-1,j,matrix,dp));
    }
    return maxsum;
}
// => Time Complexity = O(n*m) => Becoz at max we can have (m*n) states.
// => Space Complexity = O(n) + O(n*m)

Approach 3: Tabulation

#CODE:
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;++j) {
        dp[0][j] = matrix[0][j];
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<m;++j) {
            int up = matrix[i][j] + dp[i-1][j];
            int ld = matrix[i][j]; 
            int rd = matrix[i][j];
            if(j-1>=0) ld += dp[i-1][j-1];
            else ld = -1e8;
            if(j+1<m) rd += dp[i-1][j+1];
            else rd = -1e8;
            dp[i][j] = max(up,max(ld, rd));
        }
    }
    int maxsum = -1e8;
     for(int j=0;j<m;++j) {
         maxsum = max(maxsum, dp[n-1][j]);
     }
    return maxsum;
}
// => Time Complexity = O(n*m)
// => Space Complexity = O(n*m)

Approach 4: Space Optimization

#CODE:
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m,0);
    for(int j=0;j<m;++j) {
        prev[j] = matrix[0][j];
    }
    for(int i=1;i<n;++i) {
        vector<int> curr(m,0);
        for(int j=0;j<m;++j) {
            int up = matrix[i][j] + prev[j];
            int ld = matrix[i][j]; 
            int rd = matrix[i][j];
            if(j-1>=0) ld += prev[j-1];
            else ld = -1e8;
            if(j+1<m) rd += prev[j+1];
            else rd = -1e8;
            curr[j] = max(up,max(ld, rd));
        }
        prev = curr;
    }
    int maxsum = -1e8;
     for(int j=0;j<m;++j) {
         maxsum = max(maxsum, prev[j]);
     }
    return maxsum;
}
// => Time Complexity = O(n*m)
// => Space Complexity = O(2*n)