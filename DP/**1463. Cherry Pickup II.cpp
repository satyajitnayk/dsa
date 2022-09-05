Max Sum = Path Sum By Robot 1 + Robot 2

1. Express everything in iterms of (i1,j1) & (i2,j2)
2. Explore all paths & get max sum

f(i1,j1,i2,j2)
=> Since both move to same row each time we can use i instead of i1 & i2

Approach 1: Recursion

#CODE:
int f(int i,int j,int k,vector<vector<int>> &grid) {
  // cout << i << " " << j << " " << k << "\n";
  int m = grid[0].size();
  int n = grid.size();
  if(j<0 || j>=m || k<0 || k>=m) return -1e8;
  if(i==n-1) {
    if(j == k) return grid[i][j];
    else return grid[i][j] + grid[i][k];
  }
  // Express all paths for both robots
  int maxi = 0;
  for(int d1=-1;d1<=1;++d1) {
    for(int d2=-1;d2<=1;++d2) {
        int curr = 0;
        if(j == k) {
            curr += grid[i][j]; 
        } else{
            curr += grid[i][j] + grid[i][k];
        }  
        curr += f(i+1,j+d1,k+d2,grid);
        maxi = max(maxi,curr);
    }
  }
  return maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    return f(0,0,grid[0].size()-1,grid);
}
// => Time Complexity = O(3^2n)
// => Space Complexity = O(n)


Approach 2: Memoization

#CODE:
int f(int i,int j,int k,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp) {
  // cout << i << " " << j1 << " " << j2 << "\n";
  int m = grid[0].size();
  int n = grid.size();
  if(j<0 || j>=m || k<0 || k>=m) return -1e8;
  if(i==n-1) {
    if(j == k) return grid[i][j];
    else return grid[i][j] + grid[i][k];
  }
  if(dp[i][j][k] != -1) return dp[i][j][k];
  // Express all paths for both robots
  int maxi = 0;
  for(int d1=-1;d1<=1;++d1) {
    for(int d2=-1;d2<=1;++d2) {
        int curr = 0;
        if(j == k) {
            curr += grid[i][j]; 
        } else{
            curr += grid[i][j] + grid[i][k];
        }  
        curr += f(i+1,j+d1,k+d2,grid,dp);
        maxi = max(maxi,curr);
    }
  }
  return dp[i][j][k] = maxi;
}
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return f(0,0,m-1,grid,dp);
}
// => Time Complexity = O(n*m*m)
// => Space Complexity = O(n) + O(n*m*m)

Approach 3: Tabulation

#CODE:
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int j=0;j<m;++j) {
        for(int k=0;k<m;++k) {
            if(j == k) dp[n-1][j][k] = grid[n-1][j];
            else dp[n-1][j][k] =  grid[n-1][j] + grid[n-1][k];
        }
    }
    for(int i=n-2;i>=0;--i) {
        for(int j=0;j<m;++j) {
            for(int k=0;k<m;++k) {
              int maxi = 0;
              for(int d1=-1;d1<=1;++d1) {
                for(int d2=-1;d2<=1;++d2) {
                    int curr = -1e8;
                    if(j == k) {
                        curr = grid[i][j]; 
                    } else{
                        curr = grid[i][j] + grid[i][k];
                    }  
                    if(i+1<n && j+d1<m && j+d1>=0 && k+d2<m && k+d2>=0){
                        curr += dp[i+1][j+d1][k+d2];
                    } 
                    maxi = max(maxi,curr);
                }
              }
              dp[i][j][k] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
// => Time Complexity = O(n*m*m)
// => Space Complexity = O(n*m*m)

Approach 4: Space Optimization

#CODE:
int cherryPickup(vector<vector<int>>& grid) {
    int m = grid[0].size();
    int n = grid.size();
    vector<vector<int>> prev(m,vector<int>(m,0));
    for(int j=0;j<m;++j) {
        for(int k=0;k<m;++k) {
            if(j == k) prev[j][k] = grid[n-1][j];
            else prev[j][k] =  grid[n-1][j] + grid[n-1][k];
        }
    }
    for(int i=n-2;i>=0;--i) {
        vector<vector<int>> curr(m,vector<int>(m,0));
        for(int j=0;j<m;++j) {
            for(int k=0;k<m;++k) {
              int maxi = 0;
              for(int d1=-1;d1<=1;++d1) {
                for(int d2=-1;d2<=1;++d2) {
                    int curr = -1e8;
                    if(j == k) {
                        curr = grid[i][j]; 
                    } else{
                        curr = grid[i][j] + grid[i][k];
                    }  
                    if(i+1<n && j+d1<m && j+d1>=0 && k+d2<m && k+d2>=0){
                        curr += prev[j+d1][k+d2];
                    } 
                    maxi = max(maxi,curr);
                }
              }
              curr[j][k] = maxi;
            }
        }
        prev = curr;
    }
    return prev[0][m-1];
}
// => Time Complexity = O(n*m*m)
// => Space Complexity = O(m*m)