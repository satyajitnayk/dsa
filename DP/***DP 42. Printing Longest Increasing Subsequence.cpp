#CODE:
vector<int> lengthOfLIS(vector<int>& A) {
    int n = A.size();
    int maxi = 1,lastIdx=0;
    vector<int> dp(n, 1), prev(n, 1);
    for(int i=0;i<n;++i) {
        prev[i] = i;
        for(int prevIdx=0;prevIdx<i;++prevIdx) {
            if(A[prevIdx] < A[i] && dp[prevIdx]+1 > dp[i]) {
                dp[i] = 1 + dp[prevIdx];
                prev[i] = prevIdx;
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIdx = i;
        }
    }
    // construct LIS
    vector<int> ans;
    ans.push_back(A[lastIdx]);
    while(prev[lastIdx] != lastIdx) {
        lastIdx  = prev[lastIdx];
        ans.push_back(A[lastIdx]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}