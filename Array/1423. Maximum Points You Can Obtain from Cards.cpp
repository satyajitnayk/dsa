There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Approach 1: BF Recursion
Time O(3^n) & space O(3^n)

Approach 2: Optimal Approach
-> since we need to find maximum sum of elements from first & last
-> We can find a subarray of size n-k with minimum sum.
-> return totalSum - minSubArraySumOfSize_n-k

=> Time O(n) & space O(1)

#CODE:
int maxScore(vector<int>& A, int k) {
    int n = A.size();
    k=n-k;
    int curSum = 0;
    int tSum = 0;
    for(auto c:A) tSum += c;
    for(int i=0;i<k;i++) curSum += A[i];
    int minSum = curSum;
    for(int i=k;i<A.size(); i++){
        curSum = curSum - A[i-k] + A[i];
        minSum = min(minSum, curSum);
    }
    return tSum - minSum;
}