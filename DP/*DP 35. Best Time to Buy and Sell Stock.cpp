For every day check for profit & store maximum profit.

Approach :
#CODE:
int maxProfit(vector<int>& prices) {
    int minSoFar = prices[0];
    int profit = 0;
    for(int i=1;i<prices.size();++i) {
        profit = max(profit, prices[i]-minSoFar);
        minSoFar = min(minSoFar, prices[i]);
    }
    return profit;
}
=> Time Complexity = O(n)
=> Space Complexity = O(1)