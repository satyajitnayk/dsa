Approach 1: Recursion
1. This problems boils down to unbounded knapsack

#CODE:
int f(int i,int target,vector<int> &A,vector<int> &price) {
    if(i == 0) {
        return price[0] *(target/A[0]);
    }
    int nottake = f(i-1,target,A,price);
    int take = 0;
    if(A[i] <= target) {
        take = price[i] + f(i,target-A[i],A,price);
    }
    return max(take, nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<int> A;
    for(int i=1;i<=n;++i) A.push_back(i);
    return f(n-1,n,A,price);
}
=> Time Complexity = Exponetial (>>O(2^n))
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int f(int i,int target,vector<int> &A,vector<int> &price,vector<vector<int>> dp) {
    if(i == 0) {
        return price[0] *(target/A[0]);
    }
    if(dp[i][target] != -1) return dp[i][target];
    int nottake = f(i-1,target,A,price,dp);
    int take = 0;
    if(A[i] <= target) {
        take = price[i] + f(i,target-A[i],A,price,dp);
    }
    return dp[i][target] = max(take, nottake);
}
int cutRod(vector<int> &price, int n)
{
	vector<int> A;
    for(int i=1;i<=n;++i) A.push_back(i);
    int target = n;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,n,A,price,dp);
}
=> Time Complexity = O(n*target) = O(n^2)
=> Space Complexity = O(n) + O(n^2)

Approach 3: Tabulation

#CODE:
int cutRod(vector<int> &price, int n)
{
	vector<int> A;
    for(int i=1;i<=n;++i) A.push_back(i);
    int target = n;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<=target;++i) {
        dp[0][i] = price[0] *(i/A[0]);
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
            int nottake = dp[i-1][j];
            int take = 0;
            if(A[i] <= j) {
                take = price[i] + dp[i][j-A[i]];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n-1][target];
}
=> Time Complexity = O(n*target) = O(n^2)
=> Space Complexity = O(n^2)

Approach 4: Space Optimization

#CODE:
int cutRod(vector<int> &price, int n)
{
	vector<int> A;
    for(int i=1;i<=n;++i) A.push_back(i);
    int target = n;
    vector<int> prev(target+1,0), curr(target+1,0);
    for(int i=0;i<=target;++i) {
        prev[i] = price[0] *(i/A[0]);
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
            int nottake = prev[j];
            int take = 0;
            if(A[i] <= j) {
                take = price[i] + curr[j-A[i]];
            }
            curr[j] = max(take, nottake);
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target) = O(n^2)
=> Space Complexity = O(2*n)

Approach 5: Further Space Optimization

#CODE:
int cutRod(vector<int> &price, int n)
{
	vector<int> A;
    for(int i=1;i<=n;++i) A.push_back(i);
    int target = n;
    vector<int> prev(target+1,0);
    for(int i=0;i<=target;++i) {
        prev[i] = price[0] *(i/A[0]);
    }
    for(int i=1;i<n;++i) {
        for(int j=0;j<=target;++j) {
            int nottake = prev[j];
            int take = 0;
            if(A[i] <= j) {
                take = price[i] + prev[j-A[i]];
            }
            prev[j] = max(take, nottake);
        }
    }
    return prev[target];
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)

