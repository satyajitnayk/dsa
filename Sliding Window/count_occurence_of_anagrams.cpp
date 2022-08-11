Given a string S="foqxxorfxaofr" & a second string t="fox". Find number of anagrams of t in s?

Approach 1:
-> Create all anagrams of t & search in s.
-> |s| = n & |t| = m
-> Time = O(m!*m)

Approach 2: Optimal

S="foqxxorfxaofr"
t="fox", count=0   => m : 'f'=>1, 'o'=>1, 'x'=>1 , count=3
   0 1 2 3 4 5 6 7 8 9 10 11 12
S="f o x x x o r f x a o  f  r"

f='f'=>0, 'o'=>0, 'x'=>0 , count=0   cnt=1
