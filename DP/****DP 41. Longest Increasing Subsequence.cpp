=>f(i, prevIndex) => longest Increasing Subsequence starting from index i if prevIndex is 
the index of previous selected element

Approach 1: Recursion

#CODE:
int f(int i, int prevIdx,vector<int> &A) {
    if(i == A.size()) return 0;
    // 2 options , take or not take & get max of both
    // not take
    int ans= f(i+1,prevIdx,A);
    // take
    if(prevIdx == -1 || A[i] > A[prevIdx]) {
        ans = max(ans, 1 + f(i+1,i,A));
    }
    return ans;
}
int lengthOfLIS(vector<int>& A) {
    return f(0,-1,A);
}
=> Time Complexity = O(2^n) // for each index we have two options
=> Space Complexity = O(n)

Approach 2: Memoization
1. Since prevIndex range is -1 to n-1 so we can shift indexing +1 => 0 to n.
2. We need dp array of [n]*[n+1]

#CODE:
int f(int i, int prevIdx,vector<int> &A,vector<vector<int>> &dp) {
    if(i == A.size()) return 0;
    if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];
    // 2 options , take or not take & get max of both
    // not take
    int ans= f(i+1,prevIdx,A,dp);
    // take
    if(prevIdx == -1 || A[i] > A[prevIdx]) {
        ans = max(ans, 1 + f(i+1,i,A,dp));
    }
    return dp[i][prevIdx+1] = ans;
}
int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return f(0,-1,A,dp);
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n) + O(n^2)

Approach 3: Tabulation

#CODE:
int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;--i) {
        for(int prevIdx=i-1;prevIdx >= -1;--prevIdx) {
            int ans= dp[i+1][prevIdx+1];
            if(prevIdx == -1 || A[i] > A[prevIdx]) {
                ans = max(ans, 1 + dp[i+1][i+1]);
            }
            dp[i][prevIdx+1] = ans;
        }
    }
    return dp[0][0];
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n^2)

Approach 4: Space Optimization

#CODE:
int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    vector<int> prev(n+1,0), curr(n+1,0);
    for(int i=n-1;i>=0;--i) {
        for(int prevIdx=i-1;prevIdx >= -1;--prevIdx) {
            int ans= prev[prevIdx+1];
            if(prevIdx == -1 || A[i] > A[prevIdx]) {
                ans = max(ans, 1 + prev[i+1]);
            }
            curr[prevIdx+1] = ans;
        }
        prev = curr;
    }
    return prev[0];
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)

Approach 5: Non Intuitive Tabulation
1. dp[i] => length of longest Increasing Subsequence ending at ith index.

#CODE:
int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    int maxi = 1;
    vector<int> dp(n, 1);
    for(int i=0;i<n;++i) {
        for(int prev=0;prev<i;++prev) {
            if(A[prev] < A[i]) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)

Approach 6: Binary Search

#CODE:
int lengthOfLIS(vector<int>& A) {
    vector<int> tmp;
    tmp.push_back(A[0]);
    int len = 1;
    for(int i=1;i<A.size();++i) {
        if(A[i] > tmp.back()) {
            tmp.push_back(A[i]);
            len++;
        } else {
            int idx = lower_bound(tmp.begin(),tmp.end(),A[i]) - tmp.begin();
            tmp[idx] = A[i];
        }
    }
    return len;
}
*Note: tmp is not LIS.

=> Time Complexity = O(n*log n)
=> Space Complexity = O(n)