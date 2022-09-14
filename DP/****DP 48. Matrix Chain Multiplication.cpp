*Partition DP: Its kind a tough pattern.

A (m x n) ,B (p x q) 
1. A & B matrix can be multiplied if n == p 
2. #of operations = m * n * q

Ex: A , B, C => 
1. (AxB)xC
2. Ax(BxC)

*Dimension if ith matrix = A[i-1] * A[i]

Approach:
1. Starts with entire block/array.
2. Base case.
3. Try all partitions.[Run loop to try all partitions]
4. Return the best possible 2 partitions.

Option 1:
for(k=i to j-1) {
  f(i,k) , f(k+1,j)
}

Option 2:
for(k=i+1 to j) {
  f(i,k-1) , f(k,j)
}

Approach 1: Recursion

#CODE:
int f(int i, int j, int A[]) {
    if(i == j) return 0;
    int mini = 1e9;
    for(int k=i;k<j;++k) {
        int op = A[i-1] * A[k] *A[j] + f(i,k,A) + f(k+1,j,A);
        mini = min(mini, op);
    }
    return mini;
}
int matrixMultiplication(int N, int A[])
{
    return f(1,N-1,A);
}
=> Time Complexity = Exponential
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int j, int A[],vector<vector<int>> &dp) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int mini = 1e9;
    for(int k=i;k<j;++k) {
        int op = A[i-1] * A[k] *A[j] + f(i,k,A,dp) + f(k+1,j,A,dp);
        mini = min(mini, op);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(int N, int A[])
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return f(1,N-1,A,dp);
}
=> Time Complexity = O(n^3) **[n^2 for #of dp states & *n for the loop].
=> Space Complexity = O(n^2) + O(n)

Approach 3: Tabulation

#CODE:
int matrixMultiplication(int N, int A[]) {
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=0;--i) {
        for(int j=i+1;j<N;++j) {
            int mini = 1e9;
            for(int k=i;k<j;++k) {
                int op = A[i-1] * A[k] *A[j] + dp[i][k] + dp[k+1][j];
                mini = min(mini, op);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N-1];
}
=> Time Complexity = O(n^3)
=> Space Complexity = O(n^2)