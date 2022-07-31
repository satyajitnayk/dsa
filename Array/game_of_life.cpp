According to Wikipedia's article: "The Game of Life, also known simply as Life, is
 a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: 
live (represented by a 1) or dead (represented by a 0). Each cell interacts with 
its eight neighbors (horizontal, vertical, diagonal) using the following four rules
 (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the
current state, where births and deaths occur simultaneously. Given the current state of
the m x n grid board, return the next state.


Approach 1: Brutr Force
Time=O(m*n) & Space = O(m*n)

int x[8] = {0,-1,-1,-1,0,1,1,1};
int y[8] = {-1,-1,0,1,1,1,0,-1}; 
int getNextState(vector<vector<int>>& board,int r, int c) {
    int liveN = 0;
    for(int i=0;i<8;++i) {
        if(r+x[i] >= 0 && r+x[i] < board.size() && c+y[i] >= 0 && c+y[i] < board[0].size()) {
            if(board[r+x[i]][c+y[i]] == 1) liveN++;
        }
    }
    int val = 0;
    if(board[r][c] == 1) {
        if(liveN==2 || liveN==3) val= 1;
        else val= 0; 
    } else{
        if(liveN == 3) val= 1;
    } 
    return val;
}
void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> A(n, vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            A[i][j] = getNextState(board,i,j);
        }
    }
    board = A;
}

Approach 2: Optimal
use 2->newly alive & 3->nely dead

=> Time = O(m*n) & space = O(1)
CODE:
//newly alive -> 2 // newly dead->3
    int x[8] = {0,-1,-1,-1,0,1,1,1};
    int y[8] = {-1,-1,0,1,1,1,0,-1}; 
    int getneighbourCount(vector<vector<int>>& board,int r, int c) {
        int liveN = 0;
        for(int i=0;i<8;++i) {
            if(r+x[i] >= 0 && r+x[i] < board.size() && c+y[i] >= 0 && c+y[i] < board[0].size()) {
                int t= board[r+x[i]][c+y[i]];
                if(t == 1 || t==3) liveN++;
            }
        }
        return liveN;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        // vector<vector<int>> A(n, vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int ln = getneighbourCount(board,i,j);
                if(board[i][j] == 0) {
				//currently dead
				//can become alive if has exactly three live neighbours
				if(ln == 3) {
					board[i][j] = 2; //newly alive
				}
			}
			else if(board[i][j] == 1) {
				//<2 -> die
				//==2 || ==3 live
				//>3 ->die
				if(ln < 2 || ln > 3) {
					board[i][j] = 3; //newly dead
				}
			}
            }
        }
          for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j] == 2) board[i][j] = 1;
                else if(board[i][j] == 3) board[i][j] = 0;
            }
          }
    }