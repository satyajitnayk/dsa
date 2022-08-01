=> Time O(log N)

int firstIndex() {
  int start =0, end = n-1;
  int startIndex=-1;
  while(start <= end) {
    int mid = start + (end-start)/2; 
    if(A[mid] == target) {
      startIndex = mid; //
      end = mid-1; //
    }
    else if(A[mid] >target) end = mid-1;
    else start = mid+1;
  }
  return startIndex;
}


int lasttIndex() {
  int start =0, end = n-1;
  int startIndex=-1;
  while(start <= end) {
    int mid = start + (end-start)/2; 
    if(A[mid] == target) {
      startIndex = mid; //
      start = mid+1; //
    }
    else if(A[mid] >target) end = mid-1;
    else start = mid+1;
  }
  return startIndex;
}
