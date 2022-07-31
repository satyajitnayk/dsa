Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

heights [0,1,0,2,1,0,1,3,2,1,2,1]

Approach :

->Total water = summation of waterabove each building.
->water above a building depends on max building heights on left & right
->i.e. min(max_at_left, max_at_right) - heights[i]

YT link: https://www.youtube.com/watch?v=FbGG2qpNp4U&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=9

=>Time O(n) & space O(n)

CODE:

int trap(vector<int>& heights) {
   int n = heights.size();
   vector<int> maxToL(n,0);
   vector<int> maxToR(n,0);
   maxToL[0] = heights[0];
   maxToR[n-1] = heights[n-1];
   for(int i=1;i<n;++i) maxToL[i] = max(maxToL[i-1], heights[i]);
   for(int i=n-2;i>=0;--i) maxToR[i] = max(maxToR[i+1], heights[i]);
   
   int totalWater = 0;
   for(int i=0;i<n;++i) {
       totalWater += min(maxToL[i], maxToR[i]) - heights[i];
   }
   return totalWater;
}