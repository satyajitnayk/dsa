Approach 1: Recursion

#CODE:
int f(int i,vector<int>& A, int k) {
    int n = A.size();
    if(i == n) return 0;
    int maxsum = INT_MIN;
    int len = 0;
    int maxVal = INT_MIN;
    for(int j=i;j < min(n,i+k);++j) {
        len++;
        maxVal = max(maxVal, A[j]);
        int sum = len * maxVal + f(j+1,A,k,dp);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}
int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    return f(0,A,k);
}
=> Time Complexity = Exponential
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i,vector<int>& A, int k,vector<int> &dp) {
    int n = A.size();
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int maxsum = INT_MIN;
    int len = 0;
    int maxVal = INT_MIN;
    for(int j=i;j < min(n,i+k);++j) {
        len++;
        maxVal = max(maxVal, A[j]);
        int sum = len * maxVal + f(j+1,A,k,dp);
        maxsum = max(maxsum, sum);
    }
    return dp[i] = maxsum;
}
int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    vector<int> dp(n,-1);
    return f(0,A,k,dp);
}
=> Time Complexity = O(n*k)
=> Space Complexity = O(n) + O(n)

Approach 3: Tabulation

#CODE:
int maxSumAfterPartitioning(vector<int>& A, int k) {
    int n = A.size();
    vector<int> dp(n+1,0);
    for(int i=n-1; i>=0; --i) {
        int maxsum = INT_MIN;
        int len = 0;
        int maxVal = INT_MIN;
        for(int j=i;j < min(n,i+k);++j) {
            len++;
            maxVal = max(maxVal, A[j]);
            int sum = len * maxVal + dp[j+1];
            maxsum = max(maxsum, sum);
        }
        dp[i] = maxsum;
    }
    return dp[0];
}
=> Time Complexity = O(n*k)
=> Space Complexity = O(n)
