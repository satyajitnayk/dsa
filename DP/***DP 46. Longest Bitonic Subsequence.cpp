Bitonic Array=> Either Strictly Increasing OR Decreasing OR Both.

Approach :
1. Store LIS from both directions in 2 differnt array.
2. Iterate over two array & get max len from (dp1[i] + dp2[i] -1)

#CODE:
int longestBitonicSequence(vector<int>& A, int n) {
    vector<int> dp1(n, 1), dp2(n, 1);
    for(int i=0;i<n;++i) {
        for(int prevIdx=0;prevIdx<i;++prevIdx) {
            if(A[prevIdx] < A[i] && dp1[prevIdx]+1 > dp1[i]) {
                dp1[i] = 1 + dp1[prevIdx];
            }
        }
    }
    for(int i=n-1;i>=0;--i) {
        for(int prevIdx=n-1;prevIdx>i;--prevIdx) {
            if(A[prevIdx] < A[i] && dp2[prevIdx]+1 > dp2[i]) {
                dp2[i] = 1 + dp2[prevIdx];
            }
        }
    }
    int maxLen = 1;
    for(int i=0;i<n;++i) {
        maxLen = max(maxLen, dp1[i]+dp2[i]-1);
    }
    return maxLen;
} 
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)