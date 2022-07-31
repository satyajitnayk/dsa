You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the
container contains the most water.

Return the maximum amount of water a container can store.

Approach 1:Brute Force
->Iterate over all indexes & find amount of water can be stored
->Area = min(h[i], h[j]) * (j-i)
->Get max Area
Time O(n^2) Space O(1)

Approach 2: Optimized
Time O(n) & space O(1)
*Intution => Move the pointer whose value is less as water content depends on minimum height
of both walls

maxArea = 0
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 1*8 = 8 => maxArea = 8
     i               j 
     
-> A[i] < A[j] so move i forward => i++
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 7*7 = 49 => maxArea = 49
       i             j 
       
-> A[i] > A[j] so move j backward => j--
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 3*6 = 18 => maxArea = 49
       i           j 

-> A[i] > A[j] so move j backward => j--
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 8*5 = 40 => maxArea = 49
       i         j 

-> A[i] <= A[j] so move either i or j => i forward => i++
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 6*4 = 24 => maxArea = 49
         i       j 
         
-> A[i] < A[j] so move i forward => i++
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 2*3 = 6 => maxArea = 49
           i     j 

-> A[i] < A[j] so move i forward => i++
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 5*2 = 10 => maxArea = 49
             i   j 
              
-> A[i] < A[j] so move i forward => i++
     0 1 2 3 4 5 6 7 8
A = [1,8,6,2,5,4,8,3,7]  Area = min(A[i],A[j]) * (j-i) = 4*1 = 4 => maxArea = 49
               i j 
       
-> A[i] < A[j] so move i forward => i++
    i == j so canot create container => break
    return maxArea as answer
=>  maxArea = 49


CODE:

int maxArea(vector<int>& A) {
    int maxArea = 0;
    int i=0,j=A.size()-1;
    while(i < j) {
        int area = min(A[i],A[j]) * (j-i);
        maxArea = max(maxArea, area);
        if(A[i] <= A[j]) i++;
        else j--;
    }
    return maxArea;
}