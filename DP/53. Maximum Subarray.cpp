Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Approach 1: BF

maxSum = INT_MIN;
for(i=0 to n-1) {
  for(j=i+1 to n-1) {
    sum=0;
    for(k=i to j) sum+= A[k];
    maxSum = max(maxSum, sum);
  }
}
=> Time O(n^3) & space O(1)

Approach 2:
1. We can avoid the 3rd for loop.

for(i=0 to n-1) {
  sum = 0;
  for(j=i+1 to n-1) {
    sum += A[j];
    maxSum = max(maxSum, sum);
  }
}
=> Time O(n^2) & space O(1)

Approach 3: Kadane's Algorithm

int maxSubArray(vector<int>& A) {
  int sum=0, maxSum=INT_MIN;
  for(int i=0;i<A.size();++i) {
    sum += A[i];
    // sum < 0 => update sum=0 
    maxSum = max(maxSum, sum);
    if(sum<0) sum=0;
  }
  return maxSum;
}

=> Time O(n) & space O(1)