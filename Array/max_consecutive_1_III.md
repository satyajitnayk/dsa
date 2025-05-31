## Problem becomes: Get length of max subarray with max k zeros

### Bruteforce

- run 2 for loops
- try all possible length with the constrained
- store max length each zeroCount <= k

```c++
int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0, n = nums.size();
    for(int i=0; i<n; i++) {
        int count = 0;
        for(int j=i; j<n; j++) {
            if(nums[j] == 0) {
                count++;
            }
            if(count <= k) {
                maxLen = max(maxLen, j-i+1);
            } else {
                break;
            }
        }
    }
    return maxLen;
}
```

- TC: O(N^2)
- SC: O(1)

### Optimized O(N) approach using sliding window approach

```c++
int longestOnes(vector<int>& nums, int k) {
    int maxLen = 0, n = nums.size();
    int l=0,r=0, zeroCount = 0;
    while(r < n) {
        if(nums[r] == 0) {
            zeroCount++;
        }
        while(zeroCount > k) {
            if(nums[l] == 0) {
                zeroCount--;
            }
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}
```
