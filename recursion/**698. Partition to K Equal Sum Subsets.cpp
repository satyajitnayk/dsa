Given an integer array nums and an integer k, return true if it is possible to divide 
this array into k non-empty subsets whose sums are all equal.

Approach:
bool solve(int i,int bucketNo,int bucketSum,int reqSum,int k,vector<int> &A,vector<bool> &picked) {
    // BC
    if(bucketNo==k+1) return true;
    if(bucketSum == reqSum) {
        // when we get a subset with the sum start search for next bucket.
        return solve(0,bucketNo+1,0,reqSum,k,A,picked);
    }
    if(bucketSum>reqSum || i>=A.size()) return false;
    // recursive small tasks
    // if element not picked earlier,then we can pick it now
    if(!picked[i]) {
        // we have 2 choices (pick or not pick)
        // pick ith element
        bucketSum += A[i];
        picked[i] = true;
        bool op1 = solve(i+1,bucketNo,bucketSum,reqSum,k,A,picked);
        
        // leave ith element
        // backtrack
        bucketSum -= A[i];
        picked[i] = false;
        bool op2 = solve(i+1,bucketNo,bucketSum,reqSum,k,A,picked);
        
        return op1 || op2;
    } else{
        // else ignore the elements
        return solve(i+1,bucketNo,bucketSum,reqSum,k,A,picked);
    }
}
bool canPartitionKSubsets(vector<int>& A, int k) {
    // Need to construct each buckets with required sum 
    vector<bool> picked(A.size(),false);
    int sum = 0;
    for(auto c:A) sum += c;
    if(sum%k!=0) return false;
    int reqSum = sum/k;
    return solve(0,1,k,reqSum,k,A,picked);
}