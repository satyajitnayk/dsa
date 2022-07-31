Given an integer array nums of length n where all the integers of nums are in the range [1, n]
 and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.
Approach 1:BF O(n^2) time 

Approach 2: sorting & map
O(nlogn) time & O(n) space

Approach 3: Optimal 
O(n)time & constant space

1/ Find index & mark its presence
2/ If already marked that means duplicacy encounter.Add it to ans;
CODE:

vector<int> findDuplicates(vector<int>& A) {
    vector<int> ans;
    for(int i=0;i<A.size();++i){
        int idx = abs(A[i])-1;
        int val = A[idx];
        if(val<0)ans.push_back(idx+1);
        else A[idx]*=-1;
    }
    return ans;
}