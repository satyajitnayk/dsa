Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Approach 1: Brute force, with division
O(n) time with O(1) space

Approach 2:
prefix & suffix product array (suffix: product of all elements before index i) same for prefix
O(n) time & O(n) space with no division
=> consider 1st of L as 1 and last of R as 1 as no element there beofre start & after end

A [-1,1, 0,-3,3]
L [1,-1,-1, 0,0]

R [0, 0, -9,3,1]
Ans[0, 0, 9,0,0]

Approach 3:
Optimize the space used & try to use the same array
vector<int> productExceptSelf(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;++i) {
        ans[i] = ans[i-1]*A[i-1];
    }
    for(int i=n-2;i>=0;--i) {
        ans[i] = A[i+1] * ans[i];
        A[i]*=A[i+1];
    }
    return ans;
}