Approach : Using concept same as partition with given difference

1. Lets take an example: A = [1,1,1,1,1], target = 3
2. If we put few +sign & few -sign => s1: [+1,+1]  s2: [-1,-1,-1]
3. s1-s2 = target => we can use code of subsets with given difference

#CODE:

int findTargetSumWays(vector<int>& A, int d) {
    int n = A.size();
    int sum=0;
    for(auto &it:A) sum += it;
    int target = (sum-d)/2;
    if(sum-d < 0 || (sum-d) % 2) return 0;
    vector<int> prev(target+1,0);
    if(A[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    if(A[0] != 0 && A[0] <= target) prev[A[0]] = 1;
    for(int i=1;i<n;++i) {
        vector<int> curr(target+1,0);
        for(int j=0;j<=target;++j) {
          int notpick = prev[j];
          int pick = 0;
          if(j >= A[i]) pick = prev[j-A[i]];
          curr[j] = (pick + notpick);
        }
        prev = curr;
    }
    return prev[target];
}
=> Time Complexity = O(n*target)
=> Space Complexity = O(target)