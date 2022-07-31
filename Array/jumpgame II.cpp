Given an array of non-negative integers nums, you are initially positioned at the 
first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.

 
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step
from index 0 to 1, then 3 steps to the last index.

Q. Print all Paths with Minimum Jumps 

Approach 1: Optimal
ladder & stairs Approach
->At each step collect ladder if it is larger than current ladder
->go on decrementing stairs at each iteration 
->when stairs at current ladder becomes 0 jumps to next ladder stored , also increment 
    jumps & continue

=> Time O(n) & Space O(1)

##CODE:
int jump(vector<int>& A) {
    int n=A.size();
    if(n<=1) return 0;
    int ladder = A[0];
    int stairs = A[0];
    int jumps = 1;
    for(int i=1; i<n; ++i) {
        if(i == n-1) return jumps;
        if(A[i]+i > ladder) ladder = A[i]+i;
        stairs--;
        if(stairs == 0) {
            jumps++;
            stairs=ladder-i;
        }
    }
    return jumps;
}

YT Reference: "https://www.youtube.com/watch?v=vBdo7wtwlXs"