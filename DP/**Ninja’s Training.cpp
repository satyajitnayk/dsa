PROBLEM STATEMENT
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these
 three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit 
 points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
 Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
Your task is to calculate the maximum number of merit points that Ninja can earn.

Approach 1: Recursion with memoization
*last 
  0 -> choosing 0th task
  1 -> choosing 1st task
  2 -> choosing 2nd task
  3 -> choosing no task at all

int solve(int d, int last,int n, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(d == 0) {
      int maxans = 0;
      for(int i=0;i<3;++i) {
        if(i != last) {
            maxans = max(maxans, points[d][i]);
        }
      }
      return dp[d][last] = maxans;
    }
    int maxans = 0;
    if(dp[d][last] != -1) return dp[d][last];
    for(int i=0;i<3;++i) {
        if(i != last) {
            int curr = points[d][i] + solve(d-1, i, n, points,dp);;
            maxans = max(maxans, curr);
        }
    }
    return dp[d][last] = maxans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(points.size(),vector<int>(4,-1));
    // Initially pass last as 3 => no task performed last
    return solve(n-1,3,n,points,dp);
}
=> Time Complexity = O(4*3*n)
=> Space Complexity = O(4*n) + O(n)

Approach 2: Tabulation

#CODE:

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]),points[0][2]);
    
    for(int d=1;d<n;++d) { 
        for(int last=0;last<=3;++last) { 
            for(int task=0;task<3;++task) {
                if(task != last) {
                    dp[d][last] = max(dp[d][last], points[d][task]+dp[d-1][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}

=> Time Complexity = O(4*3*n)
=> Space Complexity = O(4*n)

Approach 3: Space Optimization.

#CODE:

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(max(points[0][0], points[0][1]),points[0][2]);
    
    for(int d=1;d<n;++d) { 
      vector<int> tmp(4,0);
      for(int last=0;last<=3;++last) { 
        for(int task=0;task<3;++task) {
          if(task != last) {
            tmp[last] = max(tmp[last], points[d][task]+prev[task]);
          }
        }
      }
      prev = tmp;
    }
    return prev[3];
}

=> Time Complexity = O(3*4*n)
=> Space Complexity = O(4)

