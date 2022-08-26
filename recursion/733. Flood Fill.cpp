## CODE:

void solve(vector<vector<int>>& A,int r, int c, int oldColor, int newColor) {
    // BC => if hit boundary or currentcolor != oldcolor return
    if(r<0 || c<0 || r==A.size() || c == A[0].size() || A[r][c] != oldColor || A[r][c] == newColor) return;
    
    A[r][c] = newColor;
    solve(A,r+1,c,oldColor,newColor);
    solve(A,r,c+1,oldColor,newColor);
    solve(A,r-1,c,oldColor,newColor);
    solve(A,r,c-1,oldColor,newColor);
    
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int newColor) {
    int oldColor = image[r][c];
    if(oldColor == newColor) return image;
    solve(image,r,c,oldColor,newColor);
    return image;
}