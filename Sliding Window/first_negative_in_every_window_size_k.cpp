    0   1    2  3   4    5   6  7
A: [12, -1, -7, 8, -18, 30, 16, 28]    n = 8, k=3
                i       j

Approach 1: BF
-> Iterate from i=0 to n-1
-> Get window of size k & find first -ve and print it.
-> Time O(n*k) & space O(1)

Approach 2: Sliding window

int i=0,j=0;
vector<int> l;
while(j<n) {
    if(A[j] < 0) l.push_back(A[j]);
    if(j-i+1 < k) j++;
    else if(j-i+1 == k) {
        //calculation
        if(l.size() > 0) cout << l.front();
        else cout << 0;
        if(A[i] == l.front()) l.pop_front();
        i++;j++;
    }
}

=> Time O(n) & space O(n)