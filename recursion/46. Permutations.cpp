Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.

Approach 1:

## CODE:

void solve(string s, int pos, vector<string> &ans) {
  // BC
  if(pos >= s.length()) {
    ans.push_back(s);
    return;
  }
  // do the small task bring all remaining elements to position pos
  for(int i=pos;i<s.length(); ++i) {
    swap(s[i],s[pos]); // swap
    solve(s,pos+1,ans);
    swap(s[i],s[pos]); // swap it back OR backtrack
  }

}
vector<string> permute(string &s) {
  vector<string> ans;
  solve(s,0,ans);
  return ans;
}