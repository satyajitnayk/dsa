Return the largest subarray with sum K.
A: [1,2,3,8,1,2,9,0,4,5,7,2,3]
K: 9

int i = 0, j = 0, sum = 0;
int maxLen = 0;
while (j < n) {
    sum += A[j]; // calculation
    if (sum < k) {
        j++;
    }
    else if (sum == k) {
        maxLen = max(maxLen, j-i+1); // calculation
        j++;
    }
    else if (sum > k) {
        while (sum > k) {
            sum -= A[i];
             i++;
        }
          if(sum == k){
          maxLen = max(maxLen, j-i+1);
        }
        j++;
    }
}
return maxLen;