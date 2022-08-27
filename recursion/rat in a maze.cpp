void solve(int i,int j,int n,vector<vector<int>> &arr,string &path,vector<string> &ans) {
    // BC
    if(i<0 || j<0 || i==n || j==n || arr[i][j]==0) return;
    else if(i==n-1 && j==n-1) {
        ans.push_back(path);
        return;
    } else {
        // mark i,j as visited
        arr[i][j] = 0;
        
        path.push_back('D');
        solve(i+1,j,n,arr,path,ans);
        path.pop_back();
        
        path.push_back('L');
        solve(i,j-1,n,arr,path,ans);
        path.pop_back();
        
        path.push_back('R');
        solve(i,j+1,n,arr,path,ans);
        path.pop_back();
        
        path.push_back('U');
        solve(i-1,j,n,arr,path,ans);
        path.pop_back();
        
        // back track visited
        arr[i][j] = 1;
    }
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string path;
    solve(0,0,n,arr,path,ans);
    return ans;
}