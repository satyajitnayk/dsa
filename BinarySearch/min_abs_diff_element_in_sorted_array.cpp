 0  1  2  3   4   target=12
[1, 3, 8, 10, 15]

1. If target present then use simple BS to find target.
2. Find ceil & floor of targe & return index which ever is minimum (abs(ceil-target), abs(floor-target)) 
   OR normal binary search & return 0 if target found else return index which ever is 
   minimum (abs(A[start]-target), abs(A[end]-target))


int BS(A) {
  int start =0, end = n-1;
  while(start <= end) {
    int mid = start + (end-start)/2;
    if(A[mid] == target) return A[mid];
    else if(A[mid] >target) end = mid-1;
    else start = mid+1;
  }
  if(abs(A[start]-target) < abs(A[end]-target)){
    return A[start];
  } else {
    return A[end];
  }
}