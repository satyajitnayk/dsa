Approach 1:
Brute Force
O(n^2) time & O(1) space


Approach 2:
prefix sum array & hashmp
-> result = 0
-> store prefix sum & construct hahsmap
-> at any index i find targetSum = prefix[i] - k
-> find in map if exists add map[target] to result 
=> Time O(nlogn) & space O(n)

=> time can be optimized using if (m[target] > 0 ) result += m[target]
=> Time O(n) & space O(n)

Note: Always initialize m[0] = 1 
=>  one sum exists that adds to 0, taking no elements at all

int subarraySum(vector<int>& A, int k) {
    int n = A.size();
    int p = 0, count =0;
    unordered_map<int,int> m;
    m[0] = 1;
    for(int i=0;i<n;++i)  {
        p += A[i];
        int target = p - k;
        if(m.find(target) != m.end()) {
            count += m[target];
        }
        m[p]++;
    }
    return count;
}