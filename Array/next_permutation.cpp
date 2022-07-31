For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1]
 does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Approach 1: Brute Force 
-> store all permutations & find next permutation
=> Time O(n! * n) & space O(n!)

Approach 2: Optimal => Using algorithm
Time O(n) space O(1)
Dry Run:
     0 1 2 3 4
A = [1,4,3,5,2]
k = 2
l = 3
[1,4,5,3,2] => [1,4,5,2,3]
        
##Intution behind the algorithm:
1-> We can always find there is always increasing from back of the given array
* if A=[1,2,3] => 3 considered as incresing & start decreasing at 2
2-> We need to find the index where this increasing seq break.
Indexes  0 1 2 3 4
A =     [1,4,3,5,2]
       \
 4   5  \
1  3   2 \
* For the above example we find first break at index k=2 where A[k] > A[k+1]
Next we need to chnage the prefix from A[0] to A[k-1]
3->Find the index l > k s.t A[l] > A[k] i.e get smallest number from back that is > A[k] 
4-> swap them both & now reverse all elements from A[k+1] to A[n-1]
( To get exact next permutation=> get permuatation as less as rank so write them in decreasing order)
* In step 2 if we are unable to find k then just reverse the whole array as its already
 in decreasing order
5->get the final answer
    
CODE:

void nextPermutation(vector<int>& A) {
    int n = A.size();
    int k = n-2; 
    while(k >= 0) {
        if(A[k] < A[k+1]){
            break;
        }
        k--;
    }
    if( k < 0) {
        reverse(A.begin(), A.end());
        return;
    }
    int l = n-1;
    while(l > k) {
        if(A[l] > A[k]) {
            break;
        }
        l--;
    }
    swap(A[l], A[k]);
    reverse(A.begin() + k +1, A.end());        
}