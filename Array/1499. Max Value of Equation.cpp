You are given an array points containing the coordinates of points on a 2D plane, 
sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length.
You are also given an integer k.
Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.


Time complexity: O(n) & space O(n)

##CODE
int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    // for a point i maximize (yi + yj + |xi - xj|) s.t. abs(xi-xj) <= k
    // => yi + yj -(xi-xj) => yi-xi + (xj+yj) => xj+yj is constant
    // for inde xj, only need to maximize yi-xi
    // => use max heap
    priority_queue<pair<int,int>> q;
    int ans = INT_MIN;
    for(int i=0;i<points.size();++i) {
      while((!q.empty()) && (points[i][0]-q.top().second>k)) q.pop();
      if(!q.empty()) {
        int curVal = points[i][0]+points[i][1]+q.top().first;
        ans = max(ans, curVal);
      }
      q.push({points[i][1]-points[i][0], points[i][0]});
    }
    return ans;
}