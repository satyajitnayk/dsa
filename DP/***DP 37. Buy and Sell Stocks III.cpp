Approach 1: Recursion
f(i,buy,k) => Max profit if k no of transactions allowed start from index i & initially buy allowed

#CODE:
int f(int i, int buy, int noOfTxns,vector<int> &prices) {
    if(noOfTxns == 0 || i == prices.size()) return 0;
    if(buy) {
        int op1 = -prices[i] + f(i+1,0,noOfTxns,prices);
        int op2 = 0 + f(i+1,1,noOfTxns,prices);
        return max(op1, op2);
    } else {
        int op1 = prices[i] + f(i+1,1,noOfTxns-1,prices);
        int op2 = 0 + f(i+1,0,noOfTxns,prices);
        return max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    return f(0,1,2,prices);
}
=> Time Complexity = O(2^n)
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i, int buy, int noOfTxns,vector<int> &prices,vector<vector<vector<int>>> &dp) {
    if(noOfTxns == 0 || i == prices.size()) return 0;
    if(dp[i][buy][noOfTxns] != -1) return dp[i][buy][noOfTxns];
    if(buy) {
        int op1 = -prices[i] + f(i+1,0,noOfTxns,prices,dp);
        int op2 = 0 + f(i+1,1,noOfTxns,prices,dp);
        return dp[i][buy][noOfTxns] = max(op1, op2);
    } else {
        int op1 = prices[i] + f(i+1,1,noOfTxns-1,prices,dp);
        int op2 = 0 + f(i+1,0,noOfTxns,prices,dp);
        return dp[i][buy][noOfTxns] = max(op1, op2);
    }
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,prices,dp);
}
=> Time Complexity = O(3*2*n)
=> Space Complexity = O(n) + O(3*2*n)

Approach 3: Tabulation

#CODE:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            for(int noOfTxns=1;noOfTxns<=2;++noOfTxns) {
                if(buy) {
                    int op1 = -prices[i] + dp[i+1][0][noOfTxns];
                    int op2 = 0 + dp[i+1][1][noOfTxns];
                    dp[i][buy][noOfTxns] = max(op1, op2);
                } else {
                    int op1 = prices[i] + dp[i+1][1][noOfTxns-1];
                    int op2 = 0 + dp[i+1][0][noOfTxns];
                    dp[i][buy][noOfTxns] = max(op1, op2);
                }
            }
        }
    }
    return dp[0][1][2];
}
=> Time Complexity = O(3*2*n)
=> Space Complexity = O(3*2*n)

Approach 4: Space Optimization

#CODE:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> prev(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
    for(int i=n-1;i>=0;--i) {
        for(int buy=0;buy<=1;++buy) {
            for(int noOfTxns=1;noOfTxns<=2;++noOfTxns) {
                if(buy) {
                    int op1 = -prices[i] + prev[0][noOfTxns];
                    int op2 = 0 + prev[1][noOfTxns];
                    curr[buy][noOfTxns] = max(op1, op2);
                } else {
                    int op1 = prices[i] + prev[1][noOfTxns-1];
                    int op2 = 0 + prev[0][noOfTxns];
                    curr[buy][noOfTxns] = max(op1, op2);
                }
            }
        }
        prev = curr;
    }
    return prev[1][2];
}
=> Time Complexity = O(3*2*n)
=> Space Complexity = O(1)
