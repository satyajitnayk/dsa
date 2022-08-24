Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Approach 1:
1. Follow approach of permutations, but store ans in a set instead of vector 
2. Finally convert set to vector & return ans.

##CODE:
void solve(vector<int> &A, int pos, set<vector<int>> &s) {
    // BC
    if(pos>=A.size()) {
        s.insert(A);
        return;
    }
    for(int i=pos;i<A.size();++i){
        swap(A[i],A[pos]);
        solve(A,pos+1,s);
        swap(A[i],A[pos]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& A) {
    set<vector<int>> s;
    solve(A,0,s);
    vector<vector<int>> ans;
    for(auto x: s){
        ans.push_back(x);
    }
    return ans;
}

Approach 2:
1. Folllow Approach similar to permutations.
2. but while bringing remaining elements to position check only unique element placed at position pos.
3. _    remaining elements [1,2,1] => unique [1,2]
4. While placing elements in position pos, keep track of elements that are already placed here.

##CODE:

void solve(vector<int> &A, int pos, vector<vector<int>> &s) {
    // BC
    if(pos>=A.size()) {
        s.push_back(A);
        return;
    }
    unordered_set<int> m;
    for(int i=pos;i<A.size();++i){
        // element already placed at position pos
        if(m.find(A[i]) != m.end()) continue; 
        m.insert(A[i]);
        swap(A[i],A[pos]);
        solve(A,pos+1,s);
        swap(A[i],A[pos]); // backtrack
    }
}
vector<vector<int>> permuteUnique(vector<int>& A) {
    vector<vector<int>> ans;
    solve(A,0,ans);
    return ans;
}