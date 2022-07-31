Given an array of integers heights representing the histogram""s 
bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Approach 1: BF
Try all possible rectangle & get maximum area
=> Time O(n^2) & space O(1)

Approach 2: Optimal (Using stack)

=> Time O(n) & space O(1)

**Approach :
-> At each index check how much it can expand to left & right
-> elem can expand if it have element >= itself in left or right


-> At each building fix the height as height of the building & try to expand it to left & right.
-> i.e. find next smaller to left & right
-> Find max area from  h[i] * (nsr[i]-nsl[i]-1);

=> Time O(n) & space O(n)

int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    // store nsl, nsr indexes
    vector<int> nsl, nsr;
    stack<pair<int,int>> s;
    for(int i=0;i<n;++i) {
        if(s.size() == 0) {
            nsl.push_back(-1);
        } else if( s.top().first < heights[i]) {
            nsl.push_back(s.top().second);
        } else if( s.top().first >= heights[i]) {
            while(s.size() > 0 && s.top().first >= heights[i]) s.pop();
            if(s.size() > 0) nsl.push_back(s.top().second);
            else nsl.push_back(-1);
        }
        s.push({heights[i],i});
    }
    stack<pair<int,int>> t;
    for(int i=n-1; i >= 0; --i) {
        if(t.size() == 0) {
            nsr.push_back(n);
        } else if(t.top().first < heights[i]) {
            nsr.push_back(t.top().second);
        } else if(t.top().first >= heights[i]) {
            while(t.size() >0 && t.top().first >= heights[i]) t.pop();
            if(t.size() >0) nsr.push_back(t.top().second);
            else nsr.push_back(n);
        }
        t.push({heights[i],i});
    }
    reverse(nsr.begin(), nsr.end());
    int mx = 0;
    for(int i=0;i<n;++i) {
        int area = heights[i] * (nsr[i]-nsl[i]-1);
        mx = max(mx, area);
    }
    return mx;
}