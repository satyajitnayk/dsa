An element in an sorted array can be in ith or i-1 th or i+1 th indexes.(Nearly sorted)
-> so we need to search in 3 places i, i-1, i+1
int BS_NEARLY_SORTED(A) {
  int start =0, end = n-1;
  while(start <= end) {
    int mid = start + (end-start)/2;
    if(A[mid] == target) return mid;
    else if(mid-1>=0 && A[mid-1]) return mid-1;
    else if(mid+1 <= end && A[mid+1]) return mid+1;
    else if(A[mid] >target) end = mid-2;
    else start = mid+2;
  }
  return -1; //if not found
}