A=[18,19,29,15,16]

Approach using 2 stack: O(n) space
-> 1 stack stores elements & 2nd stores the minimum element so far

->i.e. A=[18,19,29,15,16]
S : 18 19 29 15 16
t : 18 15
  1.initially stack s empty so push 1st element
  2. 19 > 18 so so not push to t
  3. same for 29
  4. 15 < 18 - push to t

  5. Also pop same element from both stack at same time