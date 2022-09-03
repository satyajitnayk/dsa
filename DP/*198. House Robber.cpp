You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you 
from robbing each of them is that adjacent houses have security systems connected and
 it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum 
amount of money you can rob tonight without alerting the police.

Approach 1: Recursion

** f(i) return max sum subsequence where no elements are adjacent to each other from 0 to index i.

int f(int i, vector<int> &A) {
  if(i == 0) return A[0];
  if(i < 0) return 0;
  // since we picked ith elem we need to move to i-2 index.
  int pick = A[i] + f(i-2, A);
  int notPick = f(i-1, A); // we can move to i-1 index 
  return max(pick, notPick);
}
=> Time = O(2^n) & Space = O(n)

Approach 2: Memoization

#CODE:
int f(int i, vector<int> &A, vector<int> &dp) {
  if(i == 0) return A[0];
  if(i < 0) return 0;
  if(dp[i] != -1) return dp[i];
  // since we picked ith elem we need to move to i-2 index.
  int pick = A[i] + f(i-2, A, dp);
  int notPick = f(i-1, A, dp); // we can move to i-1 index 
  return dp[i] = max(pick, notPick);
}
int rob(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n,-1);
    return f(n-1, A, dp);
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)

Approach 3: Tabulation.

#CODE:
int rob(vector<int>& A) {
    int n = A.size();
    vector<int> dp(n,0);
    dp[0] = A[0];
    for(int i=1;i<n;++i) {
        int pick = A[i] + ( i>=2 ? dp[i-2] : 0);
        int notPick = dp[i-1];
        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)

Approach 4: Space optimization

#CODE
int rob(vector<int>& A) {
    int n = A.size();
    int prev1 = A[0], prev2 = 0;
    int curr = 0;
    for(int i=1;i<n;++i) {
        int pick = A[i] + ( i>=2 ? prev2 : 0);
        int notPick = prev1;
        curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
=> Time Complexity = O(n)
=> Space Complexity = O(1)