Given an m x n matrix, return all elements of the matrix in spiral order.


Approach :
->define minrow,maxrow,mincolumn,maxcolumn 
->Traverse top, right, bottom, left wall and print
Time O(n) apace O(1)

CODE:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int minr = 0;
    int minc = 0;
    int maxr = matrix.size()-1;
    int maxc = matrix[0].size()-1;
    int totalCount = (maxr+1)*(maxc+1);
    vector<int> ans(totalCount,0);
    int count = 0;
    while(true) {
        if(count == totalCount) break;
        //top wall
        for(int i=minr,j=minc; j <= maxc; ++j) {
            ans[count++] = matrix[i][j];
        }
        minr++;
        if(count == totalCount) break;
        //right wall
        for(int i=minr, j=maxc; i <= maxr; ++i){
            ans[count++] = matrix[i][j];
        }
        maxc--;
        if(count == totalCount) break;
        //bottom wall
        for(int i=maxr, j=maxc; j >= minc; --j){
            ans[count++] = matrix[i][j];
        }
        maxr--;
        if(count == totalCount) break;
        //left wall
        for(int i=maxr, j = minc; i >= minr; --i){
            ans[count++] = matrix[i][j];
        }
        minc++;
       if(count == totalCount) break;
    }
    return ans;
}