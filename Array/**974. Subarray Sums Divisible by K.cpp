Given an integer array nums and an integer k, return the number of non-empty
subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example: Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


Approach 1: Using sliding window
=>Time O(n^2) & Space O(1)

int subarraysDivByK(vector<int>& A, int k) {
    int cnt = 0;
    for(int ws=1; ws<=A.size();++ws) {
        int sum = 0;
        for(int i=0;i<ws;++i) sum+=A[i];
        if(sum%k==0) cnt++;
        for(int i=ws;i<A.size();++i) {
            sum = sum + A[i] - A[i-ws];
            if(sum%k==0)cnt++;
        }
    }
    return cnt;
}

Approach 2: prefix sum + hashmap
=>Time O(n) & space O(k)

##Exaplanation

A         [4,5,0,-2,-3,1] k = 5
prefixsum [4,9,9, 7, 4,5]
        start 0          point i   point j    point m
         [ |--------------|-------------|---------|-------]
**Observations:
->If sum % k till point i = 2 & sum %k till j is also 2 & same for point m
-> That means subarray [point i to point j] sum % k = 0
-> Now we have x=3 points where we have same remainder
-> We need to choose 2 point out of x=3 to get subarray => xC2 => x*(x-1)/2
->*For remainder 0 we have x + xC2 ways to get subarray
(Bcoz we can start from 0th index & choose all x points so adding x to count)


int subarraysDivByK(vector<int>& A, int k) {
    vector<int> counts(k,0); // array to store remainders count for each prefix sum
    int prefixSum=0;
    for(auto c:A) {
      prefixSum += (c%k + k) % k;
      counts[prefixSum%k]++;
    }
    int cnt = counts[0]; // for 0 remainder, we have to add counts[0] to result
    for(auto c: counts) {
      cnt += c*(c-1)/2; // choosing 2 point out of c =>  nC2
    }
    return cnt; 
}

YT Link: https://www.youtube.com/watch?v=u9m-hnlcydk