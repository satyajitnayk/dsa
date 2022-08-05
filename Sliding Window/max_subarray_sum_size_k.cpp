Find max sum of all possible subarray of size k.

int i=0,j=0;
int mxSum = 0, sum = 0;
while(j < n) {
  sum += A[j];
  if(j-i+1 < k) j++; // window size <  k
  else if(j-i+1 == k) {
    mxSum = max(mxSum, sum);
    sum -= A[i];
    j++; i++;
  }
}
return mxSum;

=> Time O(n) & space O(1)