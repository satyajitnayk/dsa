// This Question is good only for Face to Face Round Only
->Each time double the size of search length

A: [1, 2, 3, 4, 5, 6, 7, 8, 9,...] target = 11
    s  e
-> Now apply BS
-> if target > A[e], then s=e & e = 2*e 
-> else if target < A[e], then apply BS on the range [s,e]

int start=0, end=1;
while(target > A[end]) {
  start = end;
  end *= 2;
}
return BS(A,start,end,target);


Q2/ Find index of first occurence of 1 in a infinite binary sorted array.

*Approach:
->Find the range of search from infinite sorted array.
->Apply the firstOccurence() solution to the range.
 0  1  2  3  4  5
[0, 0, 0, 0, 1, 1,....]
 s  e             
        