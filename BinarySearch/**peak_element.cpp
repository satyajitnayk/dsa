A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. 
If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always 
considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

     0  1  2  3  4  5  6  
A = [1, 2, 1, 3, 5, 6, 4]
     s        m        e    3 < 5 => A[mid] < A[mid+1] & 3 > 1 => A[mid] > A[mid-1] =>

     s  m  e    6 > 5 & 6 > 4 


CODE:

int findPeakElement(vector<int>& A) {
    int n=A.size();
    if(n==1) return 0;
    int start=0, end=n-1;
    while(start <= end) {
      int mid = start + (end-start)/2; // To avoid integer overflow
      if(mid>0 && mid<n-1) {
        //check both neighbour
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
        else if(A[mid-1] > A[mid]) end = mid-1;
        else start = mid+1;
      } else if(mid==0){
        if(A[0] > A[1]) return 0;
        else return 1;
      } else if(mid == n-1) {
        if(A[n-1] > A[n-2]) return n-1;
        else return n-2;
      }
    }
    return -1;
}