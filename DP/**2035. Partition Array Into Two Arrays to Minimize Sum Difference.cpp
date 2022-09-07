Approach: Use subset sum equals K 
1. prev store if each target possible from 0 to target.
** A[i] >= 0
#CODE:
int minSubsetSumDifference(vector<int> &A, int n)
{
	    int target = 0;
        for(auto c: A) target += c;
        if(target == 0) return 0;
        vector<bool> prev(target+1,false), curr(target+1,false);
        prev[0] = curr[0] = true;
        if(A[0] <= target) prev[A[0]] = true;
        for(int i=1;i<n;++i) {
            curr[0] = true;
            for(int j=1;j<=target;++j) {
                bool op1 = prev[j];
                bool op2 = false;
                if(A[i] <= j) op2 = prev[j-A[i]];
                curr[j] = op1 | op2;
            } 
            prev = curr;
        }
        int mindiff = 1e8;;
        for(int i=0;i<=target;++i) {
            if(prev[i]) {
                mindiff = min(mindiff, abs(target-2*i));
            }
        }
        return mindiff;
}
=> Time Complexity = O(target*n)
=> Space Complexity = O(target)