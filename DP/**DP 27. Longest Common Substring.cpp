Approach 1: Recursion
f(i,j) => Longest Common substring b/w substring s1[0...i] & s2[0...j]

#CODE:
int f(int i,int j,string &s1,string &s2,int count) {
    if(i<0 || j<0) return count;  
    if(s1[i] == s2[j]) {
        count = f(i-1,j-1,s1,s2,count+1);
    }
    count = max(count,max(f(i-1,j,s1,s2,0),f(i,j-1,s1,s2,0)));
    return count;
}
int lcs(string &s1, string &s2){
	int n = s1.size();
    int m = s2.size();
    return f(n-1,m-1,s1,s2,0);
}
=> Time Complexity = O(2^mn)
=> Space Complexity = O(m+n)

Approach 2: Tabulation
1. if char matches add 1 else reset value to 0;

#CODE:
int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0; 
        }
    }
    return ans;
}
=> Time Complexity = O(mn)
=> Space Complexity = O(mn)

Approach 3: Space Optimization

#CODE:
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<int> prev(m+1,0), curr(m+1,0);
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            }
            else curr[j] = 0; 
        }
        prev = curr;
    }
    return ans;
}
=> Time Complexity = O(mn)
=> Space Complexity = O(2*m)
