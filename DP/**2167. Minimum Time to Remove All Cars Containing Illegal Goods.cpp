Approach 1:Usinf 2 prefix array
1. 1st array store min cost to remove bug if only removal from left OR middle allowed
2. 2nd array store min cost to remove bug if only removal from right OR middle allowed
3. Now traverse both arrya & find find result combinely
             0 1 2 3 4 5 6
leftmiddle  [1,2,2,2,4,4,6]
rightmiddle [7,5,3,3,3,1,1]

ans = leftmiddle[n-1]
At index i => ans = min(ans, leftmiddle[i]+rightmiddle[i+1])

** For completed code refer 2167.png

Approach 2: Using Kadanes Algo
steps:
1. s = left + middle + right
2. ans = len(left) + 2*(#of 1's in middle) + len(right)
ans  = len(l) + len(m) + len(r) + 2*(#of 1's in middle) - len(m)
     =                        n + 2*(#of 1's in middle) - len(m)
     =                        n + 2*(#of 1's in middle) - #of 1's in middle - #of 0's in middle
     =                        n + #of 1's in middle - #of 0's in middle

     so steps reduced to minimizing (#of 1's in middle - #of 0's in middle)
     => replace all 0's by 1's
     =>[0 , 0,1,1, 0,1,1, 0, 0]
     =>[-1,-1,1,1,-1,1,1,-1,-1]
     =>Now find smallest subarray sum
     ans <- n + least subarray sum

## CODE:
int minimumTime(string s) {
    int n = s.size();
    int ans = n;
    vector<int> vec;
    for(auto it:s) {
        if(it=='0') vec.push_back(-1);
        else vec.push_back(1);
    }
    int mini = 0;
    int sum = 0;
    for(auto it: vec) {
        sum += it;
        mini = min(mini, sum);
        if(sum > 0) sum = 0;
    }
    return ans + mini;
}