Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Approach 1: Brute force
-> sort + 3 pointers + binary search
[1,0,-1,0,-2,2]
 i j k -------- =>do binary search for l to get sum=target
->store quad in hashset
=> Time O(n^3*logn) & space O(1)

Approach 2: Optimal Approach
->sort
->2 pointers & use two sum property
[1,0,-1,0,-2,2]
 i j l       r 


=>Time O(n^2*logn) & Space O(1)

CODE:

vector<vector<int>> fourSum(vector<int>& A, int target) {
    int n=A.size();
    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    for(int i=0; i < n; ++i) {
        for(int j=i+1; j<n;++j) {
            long long sumNeed = (long long)target - A[i] - A[j];
            int left = j+1;
            int right = n-1;
            while(left < right) {
                int sum = A[left]+A[right];
                if(sum < sumNeed)  left++;
                else if(sum > sumNeed)right--;
                else {
                    vector<int> q(4,0);
                    q[0] = A[i];
                    q[1] = A[j];
                    q[2] = A[left];
                    q[3] = A[right];
                    ans.push_back(q);
                    
                    // Remove duplicates
                    while(left < right && A[left] == q[2]) left++;
                    while(left < right && A[right] == q[3]) right--;
                }
            }
            
            // Remove duplicates
            while(j+1<n && A[j+1] == A[j]) ++j;
        }
        // Remove duplicates                          
        while(i+1<n && A[i+1] == A[i]) ++i;
    }
    return ans;
}
