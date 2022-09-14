1. I can do a partition at every operand
2. [T | F & T ^ F & T]
    i               j
  for(k=i+1,k<j;k+=2) {

  }
3. f1 & f2 = TRUE => A[k] == & => #ans = #waays f1 gives TRUE * #ways f2 gives TRUE
4. f1 | f2 = TRUE => A[k] == | 
  #ans = #waays f1 gives TRUE * #ways f2 gives TRUE + #waays f1 gives TRUE * #ways f2 gives FALSE 
          + #waays f1 gives FALSE * #ways f2 gives TRUE
5. f1 ^ f2 = TRUE => A[k] == ^
  #ans = #waays f1 gives TRUE * #ways f2 gives FALSE + #waays f1 gives FALSE * #ways f2 gives TRUE


Approach 1: Recursion
=> f(i,j,isTrue) => #of ways of making expression from i to j TRUE!

#CODE:

int mod = 1003;
int f(int i, int j,string &s,int isTrue) {
  if(i > j) return 0;
  if(i == j) {
    if(isTrue == 1) return s[i] == 'T';
    else return s[i] == 'F';
  }
  long long count = 0;
  for(int k=i+1; k<j; k+=2) {
    long long lT = f(i,k-1,s,1);
    long long lF = f(i,k-1,s,0);
    long long rT = f(k+1,j,s,1);
    long long rF = f(k+1,j,s,0);

    if(s[k] == '&') {
      if(isTrue == 1) {
        count = (count + (lT * rT) % mod )%mod;
      } else {
        count = (count + (lT * rF) % mod + (lF * rT) % mod
              + (lF * rF) % mod ) % mod;
      }
    } else if(s[k] == '|') {
      if(isTrue == 1) {
        count = (count + (lT * rT) % mod + (lT * rF) % mod
              + (lF * rT) % mod ) % mod;
      } else {
        count = (count + (lF * rF) % mod);
      }
    } else if(s[k] == '^') {
      if(isTrue) {
        count = (count + (lT * rF) % mod + (lF * rT) % mod ) % mod;
      } else {
        count = (count + (lT * rT) % mod + (lF * rF) % mod ) % mod;
      }
    }
  }
  return count;
}
int countWaysOfTrue(string s) {
    int n = s.size();
    return f(0,n-1,s,1);
}
=> Time Complexity = Exponential
=> Space Complexity = O(n)

Approach 2: Memoization

#CODE:
int mod = 1003;
int f(int i, int j,string &s,int isTrue,vector<vector<vector<int>>> &dp) {
  if(i > j) return 0;
  if(i == j) {
    if(isTrue == 1) return s[i] == 'T';
    else return s[i] == 'F';
  }
  if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
  long long count = 0;
  for(int k=i+1; k<j; k+=2) {
    long long lT = f(i,k-1,s,1,dp);
    long long lF = f(i,k-1,s,0,dp);
    long long rT = f(k+1,j,s,1,dp);
    long long rF = f(k+1,j,s,0,dp);

    if(s[k] == '&') {
      if(isTrue == 1) {
        count = (count + (lT * rT) % mod )%mod;
      } else {
        count = (count + (lT * rF) % mod + (lF * rT) % mod
              + (lF * rF) % mod ) % mod;
      }
    } else if(s[k] == '|') {
      if(isTrue == 1) {
        count = (count + (lT * rT) % mod + (lT * rF) % mod
              + (lF * rT) % mod ) % mod;
      } else {
        count = (count + (lF * rF) % mod);
      }
    } else if(s[k] == '^') {
      if(isTrue) {
        count = (count + (lT * rF) % mod + (lF * rT) % mod ) % mod;
      } else {
        count = (count + (lT * rT) % mod + (lF * rF) % mod ) % mod;
      }
    }
  }
  return dp[i][j][isTrue] = count;
}
int Solution::cnttrue(string s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return f(0,n-1,s,1,dp);
}
=> Time Complexity = O(2*n^3)
=> Space Complexity = O(2*n^2) + O(n)