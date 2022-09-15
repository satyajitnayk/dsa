#CODE:

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

int maximalRectangle(vector<vector<char>>& matrix) {
    // Use the above method to find area
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> A(m,0);
    int mxArea = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(matrix[i][j] == '1')  A[j]++;
            else A[j] = 0;
        }
        int area = largestRectangleArea(A);
        mxArea = max(mxArea, area);
    }
    return mxArea;
}
=> Time Complexity = O(n*m^2)
=> Space Complexity = O(m)