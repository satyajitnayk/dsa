We need to keep track of another count vector for each index.

#CODE:
int findNumberOfLIS(vector<int>& A) {
    int n = A.size();
    int maxi = 1;
    vector<int> dp(n,1), count(n,1);
    for(int i=0;i<n;++i) {
        for(int j=0;j<i;++j) {
            if(A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                // inherit the count
                count[i] = count[j];
            } else if(A[j] < A[i] && dp[j] + 1 == dp[i]) {
                // increase the count
                count[i] += count[j];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int cnt = 0;
    for(int i=0;i<n;++i) {
        if(dp[i] == maxi) cnt += count[i];
    }
    return cnt;
}
=> Time Complexity = O(n^2)
=> Space Complexity =O(2*n)