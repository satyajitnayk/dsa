Approach 1:
1. sort it as order doesn"'"t matter.
2. Use the logic of Printing Longest Increasing Subsequence.

#CODE:
vector<int> largestDivisibleSubset(vector<int>& A) {
    int n = A.size();
    sort(A.begin(), A.end());
    int lastIdx = 0, maxi=1;
    vector<int> prev(n,1), dp(n, 1);
    for(int i=0;i<n;++i) {
        prev[i] = i;
        for(int prevIdx=0;prevIdx<i;++prevIdx) {
            if((A[i] % A[prevIdx] == 0) && (dp[prevIdx] + 1 > dp[i])) {
                dp[i] = 1 + dp[prevIdx];
                prev[i] = prevIdx;
            }
        }
        if(dp[i] > maxi) {
            lastIdx = i;
            maxi = dp[i];
        }
    }
    vector<int> ans;
    ans.push_back(A[lastIdx]);
    while(prev[lastIdx] != lastIdx) {
        lastIdx  = prev[lastIdx];
        ans.push_back(A[lastIdx]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)