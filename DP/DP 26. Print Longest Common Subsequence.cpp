string printLongestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(s1[i] == s2[j]) dp[i][j] = 1 + ((i>0 && j>0) ? dp[i-1][j-1] : 0);
            else {
                int op1 = (i>0 ? dp[i-1][j] : 0);
                int op2 = (j>0 ? dp[i][j-1] : 0);
                dp[i][j] = max(op1, op2);
            }
        }
    }
    
    string s;
    int i=n;j=m;
    while(i>0 && j>0) {
      if(s1[i-1] == s2[j-1]) {
        s += s1[i-1];
        i--; j--;
      } else if(dp[i-1][j] < dp[i][j-1])  j--;
      else i--;
    }
    return reverse(s.begin(),s.end());
}
=> Time Complexity = O(n*m)
=> Space Complexity = O(n*m)