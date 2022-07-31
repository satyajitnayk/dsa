Given a rows x cols binary matrix filled with 0's and 1's, find the largest 
rectangle containing only 1's and return its area.

0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0


=> For solution refer to image attached
              heights    MAH
0 1 1 0  => [0,1,1,0]    2


0 1 1 0 
1 1 1 1  => [1,2,2,1]    4


0 1 1 0
1 1 1 1
1 1 1 1  => [2,3,3,2]    8


0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0  => [3,4,0,0]    6
=> we are making last 2 heights as 0 becoz base is 0

** Now the original question changed to finding Max Area Of rectangle in a histogram.

=> Ans is maximum of all area => 8

=> Time O(n*n) & space O(n)