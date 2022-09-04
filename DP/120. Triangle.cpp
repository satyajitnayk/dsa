[[2],[3,4],[6,5,7],[4,1,8,3]]

2
3, 4
6, 5, 7
4, 1, 8, 3
Given a triangle array, return the minimum path sum from top to bottom.

Approach 1: Recursion
f(i,j) => minimum cost to move from (i,j) to last row.

#CODE:
int f(int i, int j, int n,vector<vector<int>>& triangle) {
    if(i == n-1) return triangle[n-1][j];
    if(i == n || j == n) return INT_MAX;
    int down = triangle[i][j];
    int diagonal = triangle[i][j];
    if(i < n-1) down += f(i+1,j,n,triangle);
    if(j < n-1) diagonal +=  f(i+1,j+1,n,triangle); 
    return min(down, diagonal);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return f(0,0,n,triangle);
}
=> Time Complexity = O(2^(n*m))
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int j, int n, int m,vector<vector<int>>& triangle,vector<vector<int>> &dp) {
    if(i == n-1) return triangle[n-1][j];
    if(i == n || j == m) return INT_MAX;
    if(dp[i][j] != -1) return dp[i][j];
    int down = triangle[i][j];
    int diagonal = triangle[i][j];
    if(i < n-1) down += f(i+1,j,n,m,triangle,dp);
    if(j < m-1) diagonal +=  f(i+1,j+1,n,m,triangle,dp); 
    return dp[i][j] = min(down, diagonal);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[n-1].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(0,0,n,m,triangle,dp);
}
=> Time Complexity = O(n*n)
=> Space Complexity = O(n) + O(n*m)

Approach 3: Tabulation

#CODE:
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;--i) dp[n-1][i] = triangle[n-1][i];
    for(int i=n-2;i>=0;--i) {
        for(int j=i;j>=0;--j) {
            int down = triangle[i][j] + dp[i+1][j+1];;
            int diagonal = triangle[i][j] + dp[i+1][j];
            dp[i][j] = min(down, diagonal); 
        }
    }
    return dp[0][0];
}
=> Time Complexity = O(n*n)
=> Space Complexity = O(n*m)

Approach 4: Space Optimization

#CODE:
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> prev(n,0);
    for(int i=n-1;i>=0;--i) prev[i] = triangle[n-1][i];
    for(int i=n-2;i>=0;--i) {
        vector<int> curr(n,0);
        for(int j=i;j>=0;--j) {
            int down = triangle[i][j] + prev[j+1];
            int diagonal = triangle[i][j] + prev[j];
            curr[j] = min(down, diagonal); 
        }
        prev = curr;
    }
    return prev[0];
}
=> Time Complexity = O(n*n)
=> Space Complexity = O(2*n)