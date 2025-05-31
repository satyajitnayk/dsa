// Q. Find element in a sorted arrya.
// = > Time O(log n)

int BS(A) {
  int start = 0, end = n - 1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (A[mid] == target)
      return mid;
    else if (A[mid] > target)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1; // if not found
}
Q.If order not given(can be ASC / DESC).How u will do BS ?
