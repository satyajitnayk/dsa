1. Use Front Partition.
2. [abab] => 1 + [bab]
3. f(i) => min no of partions to make all substring from s[i...n-1] palindrome

Approach 1: Recursion

#CODE:
bool isPalindrome(int i, int j,string &s) {
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
int f(int i,string &s) {
    int n = s.size();
    if(i == n) return 0;
    int mincost = INT_MAX;
    for(int j=i;j<n;++j) {
        // partition is possible if s[i...j] is palindrome
        if(isPalindrome(i,j,s)) {
            int cost = 1 + f(j+1,s);
            mincost = min(mincost, cost);
        }
    }
    return mincost;
}
int minCut(string s) {
    int n = s.size();
    // -1 : As we are doing additional partition after last character.
    return f(0,s) - 1;
}
=> Time Complexity = Exponential
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
bool isPalindrome(int i, int j,string &s) {
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
int f(int i,string &s,vector<int> &dp) {
    int n = s.size();
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int mincost = INT_MAX;
    for(int j=i;j<n;++j) {
        // partition is possible if s[i...j] is palindrome
        if(isPalindrome(i,j,s)) {
            int cost = 1 + f(j+1,s,dp);
            mincost = min(mincost, cost);
        }
    }
    return dp[i] = mincost;
}
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n,-1);
    return f(0,s,dp) - 1;
}
=> Time Complexity = O(n^2) => n for no of states & n for checking is palindrome
=> Space Complexity = O(n) + O(n)

Approach 3: Tabulation

#CODE:
bool isPalindrome(int i, int j,string &s) {
    while(i<j) {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;--i) {
        int mincost = INT_MAX;
        for(int j=i;j<n;++j) {
            // partition is possible if s[i...j] is palindrome
            if(isPalindrome(i,j,s)) {
                int cost = 1 + dp[j+1];
                mincost = min(mincost, cost);
            }
        }
        dp[i] = mincost;
    }
    return dp[0] - 1;
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)