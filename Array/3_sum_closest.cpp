Given an integer array nums of length n and an integer target,
 find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Approach 1: BruteForce 
->Run 3 for loops & find Sum that differ least from target 
=>Time O(n^3) & space O(1)

Approach 2: Optimal
-> Sort the array
-> Run 1 for loop
-> take start=i+1 & end=n-1
-> find Sum that differ least from target 
=> Time O(n^2) & sapce O(1)

int threeSumClosest(vector<int>& A, int target) {
    int n =A.size();
    int minDiff = INT_MAX;
    int minSum = 0;
    sort(A.begin(), A.end());
    for(int i=0; i < n;++i) {
        int s = i+1;
        int e = n-1;
        while(s<e) {
            int currSum = A[i]+A[s]+A[e]; 
            if(abs(target-currSum) < minDiff) {
                minDiff = abs(target-currSum);
                minSum = currSum;
            }
            if(currSum < target) {
                s++;
            } else {
                e--;
            }
        }
    }
    return minSum;
            
}