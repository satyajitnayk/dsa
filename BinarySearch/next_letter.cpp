S: ['a','c','f','h']
key: 'f'
Q. Find next greate letter of character key. i.e. 'f'

Approach :
->Consider this as finding ceiling of character key problem.


int start=0,end=n-1, result='#'; // assuming # not present in S
while(start <= end) {
  int mid = start + (end-start)/2;
  if(S[mid] == key) start = mid+1;
  else if(S[mid] > key){
    end = mid -1;
    result = mid; // store possible candidate for answer
  }
  else start = mid+1;
}
return result;