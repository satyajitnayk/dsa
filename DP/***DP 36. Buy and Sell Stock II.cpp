Express everything in term of (i, buy)

Approach 1: Recursion
#CODE:
// buy: 1 => can buy, 0 => can not buy
// f(0,1) => starting on 0th day with buy what is the max profit
int f(int i, int buy, vector<int> &prices) {
    if(i==prices.size()) return 0;
    if(buy == 1) {
        // 2options buy or not buy
        int op1 = -prices[i] + f(i+1,0,prices);// once buy need to sell next
        int op2 = 0 + f(i+1, 1,prices); // not buy yet so buy next
        return max(op1, op2);
    } else {
        // selling 
        int op1 = prices[i] + f(i+1, 1,prices); // once sold need to buy next
        int op2 = 0 + f(i+1, 0,prices); // not sell so sell next
        return max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    return f(0,1,prices);
}
=> Time Complexity = O(2^n) // for each index buy or not buy
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
// buy: 1 => can buy, 0 => can not buy
// f(0,1) => starting on 0th day with buy what is the max profit
int f(int i, int buy, vector<int> &prices,vector<vector<int>> &dp) {
    if(i==prices.size()) return 0;
    if(dp[i][buy] != -1) return dp[i][buy];
    if(buy == 1) {
        // 2options buy or not buy
        int op1 = -prices[i] + f(i+1,0,prices,dp);// once buy need to sell next
        int op2 = 0 + f(i+1, 1,prices,dp); // not buy yet so buy next
        return dp[i][buy] = max(op1, op2);
    } else {
        // selling 
        int op1 = prices[i] + f(i+1, 1,prices,dp); // once sold need to buy next
        int op2 = 0 + f(i+1, 0,prices,dp); // not sell so sell next
        return dp[i][buy] = max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,dp);
}
=> Time Complexity = O(n)
=> Space Complexity = O(2*n) + O(n)

Approach 3: Tabulation

#CODE:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<2;++buy) {
            if(buy == 1) {
                // 2options buy or not buy
                // once buy need to sell next
                int op1 = -prices[i] + dp[i+1][0];
                // not buy yet so buy next
                int op2 = 0 + dp[i+1][1]; 
                dp[i][buy] = max(op1, op2);
            } else {
                // selling 
                // once sold need to buy next
                int op1 = prices[i] + dp[i+1][1]; 
                // not sell so sell next
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
    vector<int> prev(2,0), curr(2,0);
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<2;++buy) {
            if(buy == 1) {
                // 2options buy or not buy
                // once buy need to sell next
                int op1 = -prices[i] + prev[0];
                // not buy yet so buy next
                int op2 = 0 + prev[1]; 
                curr[buy] = max(op1, op2);
            } else {
                // selling 
                // once sold need to buy next
                int op1 = prices[i] + prev[1]; 
                // not sell so sell next
                int op2 = 0 + prev[0]; 
                curr[buy] = max(op1, op2);
            }
        }
        prev = curr;
    }
    return prev[1];
}
=> Time Complexity = O(n)
=> Space Complexity = O(1)
