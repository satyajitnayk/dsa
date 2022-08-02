#of time a sorted array is rotated?

Approach:
-> If we could find the index of the minimum element our problem is solved.
-> If an element < both left & right neighbour => it is the smllest element.
-> Alaways discard sorted part as we will find minimum element in un-sorted part.

int start = 0, end = n-1;
while(start <= end) {
  int mid = start + (end-start)/2;
  int next = A[(mid+1)%n];
  int prev = A[(mid+n-1)%n];
  if(A[mid] < prev && A[mid] < next) {
    return mid;
  } else if(A[start] <= A[mid]) {
    start = mid+1;
  } else{
    end = mid-1;
  }
}

0 1 2 3 4 5 6
5,6,7,1,2,3,4
s   m       e
      s m   e
      s
      e
      m

      => return 3