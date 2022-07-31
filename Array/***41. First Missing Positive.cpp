Given an unsorted integer array nums, return the smallest missing positive integer.
You must implement an algorithm that runs in O(n) time and uses constant extra space.

Approach 1: BF
->Start from 1 till end
->Search in the entire array for 1... same for 2 , 3, 4, ...
->If any number missing then return it

=> Time O(n^2)

Approach 2:sorting & traversing & checking if current number != prev number ,then return it
=> O(nlogn)

Approach x: optimal
intuition: Iterate over all elements 
till  A[i] > 0 => swap A[i] with A[A[i]-1] =>so that +ve values goes to their actual places
i.e. 5 goes to index 4, 3 to 2, 7 to 6 ...etc
*Note:
When we find 5, then swap it with A[4].
At last, the first place where its number is not right, return the place + 1.

i.e in the array [3,4,-1,1]
->3 > 0 => swap 3 with A[3-1] = A[2] = -1 => [-1,4,3,1]
->4 > 0 => swap 4 with A[4-1] = A[3] = 1  => [-1,1,3,4]
....

Now when loop completed check if A[i] != i+1 => if any element > 0 & not present in its place 
=> Thats our answer -> first missing +ve number


CODE:

int firstMissingPositive(vector<int>& A) {
    int n = A.size();
    for(int i=0;i<n;++i) {
        while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        }
    }
    for(int i=0;i<n;++i) {
      // element which is not in its proper place
        if(A[i] != i+1) {
            return i+1;
        }
    }
    return n+1;
}