Given an m x n grid of characters board and a string word, return true if word exists in the grid.
Time 
Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

class Solution {
public:
    int x[4] = {-1,0,1,0};
    int y[4] = {0,1,0,-1};
    bool solve(vector<vector<char>>& board, string word, int r, int c,int idx) {
        // bc
        if(idx == word.length()) return true;
        if(r <0 || c< 0 || r >= board.size() || c >= board[0].size() ) return false;
        
        if(word[idx] != board[r][c]) return false;
        char ch = board[r][c];
        board[r][c] = '@';
        
        for(int i=0;i<4;++i){
            bool res = solve(board,word,r+x[i],c+y[i],idx+1); 
            if(res) {
                board[r][c] = ch;
                return res;
            }
        }
        board[r][c] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();       
        int cols = board[0].size();
        bool res = false;
        for(int i=0; i <rows;++i){
            for(int j=0;j<cols; ++j) {
                if(word[0] != board[i][j]) continue;
                res = solve(board,word,i,j,0);
                if(res) return res;
            }
        }
        return res;

    }
};