The n-queens puzzle is the problem of placing n queens on an n x n chessboard such 
that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens"'" placement, where 'Q' and '.'
both indicate a queen and an empty space, respectively.

Approach 1:
1. We need to place excatly 1 Queen per row.
2. Check for each position if current place is same
3. isSafe taking O(n) time

=> Time O(n!)
=> Space O(n^2)

## CODE:

bool isSafe(int i, int j, vector<vector<char>> &board,int n) {
    // UP
    int tmpi = i;
    while(tmpi>=0) {
        if(board[tmpi][j] == 'Q') return false;
        tmpi--;
    }
    // TOP RIGHT
    tmpi = i; int tmpj = j;
    while(tmpi>=0 && tmpj<n) {
        if(board[tmpi][tmpj] == 'Q') return false;
        tmpi--; tmpj++;
    } 
    // TOP LEFT
    tmpi = i; tmpj = j;
    while(tmpi>=0 && tmpj>=0) {
        if(board[tmpi][tmpj] =='Q') return false;
        tmpi--; tmpj--;
    }
    return true;
}
void solve(int i, int n,vector<vector<char>> &board, vector<vector<string>> &ans) {
    // BC
    if(i==n) {
        // display(board);
        vector<string> x;
        for(int j=0;j<n;++j){
            string s="";
            for(int k=0;k<n;++k) {
                s += board[j][k];
            }
            x.push_back(s);
        }
        ans.push_back(x);    
        return;
    }
    for(int j=0;j<n;++j) {
        if(isSafe(i,j,board,n)) {
            board[i][j] = 'Q';
            solve(i+1,n,board,ans);
            board[i][j] = '.'; // backtrack
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> board(n,vector<char>(n,'.'));
    solve(0,n,board,ans);
    return ans;
}

Approach 2:
1. We can replace isSafe function by something else to work in O(1) time instead of O(n).
2. This can be done using vectors to represent row, column, diagonal.

## CODE:

void solve(int i, int n,vector<vector<char>> &board, vector<vector<string>> &ans,vector<bool> col,vector<bool> d1,vector<bool> d2) {
  // BC
  if(i==n) {
      vector<string> x;
      for(int j=0;j<n;++j){
          string s="";
          for(int k=0;k<n;++k) {
              s += board[j][k];
          }
          x.push_back(s);
      }
      ans.push_back(x);    
      return;
  }
  for(int j=0;j<n;++j) {
      if(col[j] == false && d1[i-j+n-1] == false && d2[i+j] == false) {
          board[i][j] = 'Q';
          // mark respective places as visited/unsafe
          col[j] = d1[i-j+n-1] = d2[i+j] = true;
          solve(i+1,n,board,ans,col,d1,d2);
          // backtrack & mark place as safe
          col[j] = d1[i-j+n-1] = d2[i+j] = false;
          board[i][j] = '.'; 
      }
  }
}
vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> ans;
  vector<vector<char>> board(n,vector<char>(n,'.'));
  // column already field, // diagonal1 => diagonal no: (i+j)
  // diagonal2 =>  diagonal no: (i-j+n-1)
  vector<bool> col(n,false), d1(2*n,false), d2(2*n,false);
  solve(0,n,board,ans,col,d1,d2);
  return ans;
}