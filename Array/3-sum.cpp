Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[1] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Approach 1:
->Run 3 loops 
-> check sum, if sum==0, store 3 numbers in sorted order in a set
Time O(n^3 log m)
Space )(m) => m - size of set

Approach 2:
-> Run for loop and store count of number in a map
-> run 2 foor loop
-> whene ever iterate over the two numbers remove them from map 
->find the third number in the map & store it in sorted order in a map
-> add the 2 numbers back to map
Time O(n^2 log m)
Space O(m)  m - size of set


Approach 3: 2 pointer Approach

a+b+c=0 => a+b = -c
-> Run a foor loop and set target = -(A[i])
-> set two pointer at i+1 and n-1 
-> iterate till start < end 
-> check if A[start]+A[end] == target
-> if yes store result & skip any duplicate numbers ahead
-> if sum > target decrease end => end--
-> else start ++
-> skip dupliactes

Time O(n^2)
Space O(m) -> size of ans

vector<vector<int>> threeSum(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        int n =A.size();
        for(int i=0; i<n; ++i) {
            int target = -A[i];
            int s = i+1;
            int e = n-1;
            while(s<e){
                if(A[s]+A[e] == target){
                    ans.push_back({A[i],A[s],A[e]});
                    while(s < e && A[s] == A[s+1]) s++;
                    while(s < e && A[e] == A[e-1]) e--;
                    s++;e--;
                } else if(A[s]+A[e] > target) {
                    e--;
                } else {
                    s++;
                }
            }
            while(i+1 < n && A[i+1] == A[i]) i++;
        }
        return ans;
    }