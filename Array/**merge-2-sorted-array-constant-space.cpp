Approach 1: 
1. Uisng 3rd array to store final answer. 
2. Time O(n+m) & space O(n+m)

Approach 2: using insertion sort
1. start i=0 => till i == n
2. if A[i] < B[0]: i++;
3. else swap i & 0 value & put B[0] in proper sorted position using insertion sort

=>Time complexity = O(n*m)
=>Space O(1)

#CODE:
void merge(vector<int>& A, int n, vector<int>& B, int m) {
    if(B.size() == 0) return;
    int i,k;
    for(i=0; i<n; ++i) {
        if(A[i] > B[0]) swap(A[i], B[0]);
        // place B[0] in its proper place
        int first=B[0];
        for(k=1;k<m && B[k] < first; ++k) {
            B[k-1] = B[k];
        }
        B[k-1] = first;
    }
    i=n;
    while(i<A.size()) {
        A[i] = B[i-n];
        i++;
    }
}

Approach 3: Gap method( No as such intution for it) => do it if asked for further optimiaztion
1. set initial gap=(m+n)/2;
3. do till gap > 0
  3. set i=0, j= gap;
  4. if(elem at i is > elem at gap) swap(ith , jth);
  5. gap = gap/2

=> Time complexity O((n+m)*log(n+m)) & Space O(1)

#CODE:
void merge(vector<int>& A, int n, vector<int>& B, int m) {
    int gap = ceil((float)(n+m) / 2);
    while(gap > 0) {
        int i=0, j=gap;
        while(j<(n+m)) {
            if(j < n && A[i] > A[j]) {
                swap(A[i], A[j]);
            } else if(i<n && j>=n && A[i] > B[j-n]){
                swap(A[i], B[j-n]);
            } else if(i>=n && j>=n && B[i-n] > B[j-n]){
                swap(B[i-n],B[j-n]);   
            }
            i++;
            j++;
        }
        if (gap == 1) {
          gap = 0;
        } else {
          gap = ceil((float) gap / 2);
        }
    }
    int i=0;
    while(i < m) {
        A[i+n] = B[i];
        i++;
    }
}