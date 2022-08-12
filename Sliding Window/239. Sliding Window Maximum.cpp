You are given an array of integers nums, there is a sliding window of size k which 
is moving from the very left of the array to the very right. You can only see the k 
numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7



Approach 1: BF

Approach 2: slliding window + max heap/priority_queue

=> Time O(n) & space O(n)

vector<int> maxSlidingWindow(vector<int>& A, int k) {
    vector<int> ans;
    int i=0,j=0;
    list<int> l;
    while(j<A.size()) {
      // remove all elements < A[j] in list 
      while(l.size()>0 && l.back() < A[j]) l.pop_back();
      // push A[j] to list
      l.push_back(A[j]);
      if(j-i+1 == k) {
        ans.push_back(l.front());
        // remove if A[i] present in list
        if(A[i] == l.front()) l.pop_front();
        i++;
      }
      j++;
    }
    return ans;
}