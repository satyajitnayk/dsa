The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.


Approach 1: BF 
1. Generate all permutaions & store them
2. sort them & get the kth permutation.
=> Time complexity = O(n*n!) + O(n!*log(n!))

Approach 2: Optimal Solution.
1. See attached png
=> Time complexity= O(n*n)
=> Space complexity = O(n)
