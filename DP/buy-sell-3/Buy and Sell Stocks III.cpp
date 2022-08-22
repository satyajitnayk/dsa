You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Approach:
Traverse from L->R & at each day store max profit if allowed to buy-sell upto that day. Also store buy & sell day.
Traverse from R->L & at each day store max profit if allowed to buy-sell after that day. Also store buy & sell day.
At each index store sum of above two values & get max value as answer.

## CODE:
=>Time O(n) & space O(n)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // traverse L->R
    int mpist = 0;//max profit if sold today
    int leastsf = prices[0]; // least so far
    int mpisut[n]; // max profit if sold upto today
    for(int i=1;i<n;++i) {
        if(prices[i]<leastsf) leastsf = prices[i];
        mpist = prices[i] - leastsf;
        mpisut[i] = mpist > mpisut[i-1] ? mpist : mpisut[i-1];
    }
    
    // traverse R->L
    int mpibt = 0; // max profit if bought today
    int maxat = prices[n-1]; //max after today
    int mpibtorat[n]; // max profit if bought today or after today
    for(int i=n-2;i>=0;--i) {
        if(prices[i]>maxat) maxat = prices[i];
        mpibt = maxat - prices[i];
        mpibtorat[i] = mpibt > mpibtorat[i+1] ? mpibt : mpibtorat[i+1];
    }
    
    // iterate and add & get max as answer
    int ans = 0;
    for(int i=0;i<n;++i) {
        int sum = mpisut[i] + mpibtorat[i];
        ans = max(ans, sum);
    }
    return ans;  
}