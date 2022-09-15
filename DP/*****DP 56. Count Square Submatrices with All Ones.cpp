Approach 1: Brute Force

1. Iterate over all cell & count no of square that can be expanded.
2. Time Complexity = O(n^3)

Approach 2: Tabulation

*Note: We will use Tabulation instead of recursion as recursion is not intuitive for matrix problems.
=> dp[i][j] => #of squares whose right bottom cell ends is A[i][j]

#CODE:
int countSquares(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(i==0 || j==0) dp[i][j] = matrix[i][j];
            else if(matrix[i][j] == 1) {
              dp[i][j] = matrix[i][j] + min(dp[i-1][j],min(dp[i-1][j-1], dp[i][j-1]));
            }
            count += dp[i][j];
        }
    }
    return count;
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n^2)