s1 = "abcd"
s2 = "anc"
    
lcs = "ac"
#of chars to add = len(s2) - len(lcs)
#of chars to remove = len(s1) - len(lcs)
=> ans = len(s1) + len(s2) - 2*len(lcs)
