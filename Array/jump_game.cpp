You are given an integer array nums. You are initially positioned at the array
first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Approach 1: Recursion/backtracking


Approach 2: Iterative approach
-> At each index of the array get the maximum reachable distance.
-> If finally we can reach nth index => true, else false

=> time O(n) & space O(1)

bool canJump(vector<int>& A) {
    int reachable = 0;
    for (int i = 0;i < A.size(); ++i) {
        if(reachable < i) return false;
        reachable = max(i + A[i], reachable);
    }
    return true;
}