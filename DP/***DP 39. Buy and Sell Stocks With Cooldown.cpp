1. Cool down => Can not buy right after buy.
2. So when we sell on ith day we move to i+2 day.

Approach 1: Recursion

#CODE:
int f(int i, int buy, vector<int> &prices) {
    if(i >= prices.size()) return 0;
    if(buy) {
        int op1 = -prices[i] + f(i+1,0,prices);
        int op2 = 0 + f(i+1,1,prices);
        return max(op1, op2);
    } else {
        int op1 = prices[i] + f(i+2,1,prices);
        int op2 = 0 + f(i+1,0,prices);
        return max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return f(0,1,prices);
}
=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int buy, vector<int> &prices,vector<vector<int>> &dp) {
    if(i >= prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    if(buy) {
        int op1 = -prices[i] + f(i+1,0,prices,dp);
        int op2 = 0 + f(i+1,1,prices,dp);
        return dp[i][buy] = max(op1, op2);
    } else {
        int op1 = prices[i] + f(i+2,1,prices,dp);
        int op2 = 0 + f(i+1,0,prices,dp);
        return dp[i][buy] = max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,dp);
}
=> Time Complexity = O(2*n)
=> Space Complexity = O(n) + O(2*n)

Approach 3: Tabulation

#CODE:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            if(buy) {
                int op1 = -prices[i] + dp[i+1][0];
                int op2 = 0 + dp[i+1][1];
                dp[i][buy] = max(op1, op2);
            } else {
                int op1 = prices[i] + dp[i+2][1];
                int op2 = 0 + dp[i+1][0];
                dp[i][buy] = max(op1, op2);
            }
        }
    }
    return dp[0][1];
}
=> Time Complexity = O(2*n)
=> Space Complexity = O(2*n)

Approach 4: Space Optimization

#CODE:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev1(2,0), prev2(2,0), curr(2,0);
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            if(buy) {
                int op1 = -prices[i] + prev1[0];
                int op2 = 0 + prev1[1];
                curr[buy] = max(op1, op2);
            } else {
                int op1 = prices[i] + prev2[1];
                int op2 = 0 + prev1[0];
                curr[buy] = max(op1, op2);
            }
        }
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1[1];
}
=> Time Complexity = O(2*n)
=> Space Complexity = O(1)