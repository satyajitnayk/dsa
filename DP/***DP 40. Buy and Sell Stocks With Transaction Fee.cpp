1. Similar to problem buy-sell stock II.
2. While completing a txn i.e. selling remove fee from total profit.

Approach 1: Recursion

#CODE:
int f(int i, int buy, vector<int> &prices, int fee) {
    if(i==prices.size()) return 0;
    if(buy == 1) {
        // 2options buy or not buy
        int op1 = -prices[i] + f(i+1,0,prices,fee);
        int op2 = 0 + f(i+1, 1,prices,fee);
        return max(op1, op2);
    } else {
        // selling 
        int op1 = prices[i] - fee + f(i+1, 1,prices,fee); 
        int op2 = 0 + f(i+1, 0,prices,fee);
        return max(op1, op2);
    }
}
int maxProfit(vector<int>& prices,int fee) {
    return f(0,1,prices,fee);
}
=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int buy, vector<int> &prices, int fee,vector<vector<int>> &dp) {
    if(i==prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    if(buy == 1) {
        // 2options buy or not buy
        int op1 = -prices[i] + f(i+1,0,prices,fee,dp);
        int op2 = 0 + f(i+1, 1,prices,fee,dp);
        return dp[i][buy] = max(op1, op2);
    } else {
        // selling 
        int op1 = prices[i] - fee + f(i+1, 1,prices,fee,dp); 
        int op2 = 0 + f(i+1, 0,prices,fee,dp);
        return dp[i][buy] = max(op1, op2);
    }
}
int maxProfit(vector<int>& prices,int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,fee,dp);
}
=> Time Complexity = O(2*n)
=> Space Complexity = O(n) + O(2*n)

Approach 3: Tabulation

#CODE:
int maxProfit(vector<int>& prices,int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            if(buy == 1) {
                // 2options buy or not buy
                int op1 = -prices[i] + dp[i+1][0];
                int op2 = 0 + dp[i+1][1];;
                dp[i][buy] = max(op1, op2);
            } else {
                // selling 
                int op1 = prices[i] - fee + dp[i+1][1]; 
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
int maxProfit(vector<int>& prices,int fee) {
    int n = prices.size();
    vector<int> prev(2,0), curr(2,0);
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            if(buy == 1) {
                // 2options buy or not buy
                int op1 = -prices[i] + prev[0];
                int op2 = 0 + prev[1];;
                curr[buy] = max(op1, op2);
            } else {
                // selling 
                int op1 = prices[i] - fee + prev[1]; 
                int op2 = 0 + prev[0];
                curr[buy] = max(op1, op2);
            }
        }
        prev = curr;
    }
    return prev[1];
}
=> Time Complexity = O(2*n)
=> Space Complexity = O(1)