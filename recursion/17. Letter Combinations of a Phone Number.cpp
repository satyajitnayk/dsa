Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

Approach:
1. For ex we have string s="234"
2. if we could replace s[0]=2 by its possible chars each
  time & ask recursion to solve from index i+1 till end.
3. BC: if i == s.size() pushback tmp in ans & return.


void solve(string &digits, int i, string &tmp, vector<string> &ans,unordered_map<char,string> &m) {
    //BC: whenever i reaches end add tmp to ans & return
    if(i==digits.size()) {
        ans.push_back(tmp);
        return;
    }
    string str = m[digits[i]];
    // get the string & ierate over all chars & ask 
    // recursion to solve remaining task
    for(int j=0;j<str.size();++j){
        tmp.push_back(str[j]);
        solve(digits,i+1,tmp,ans,m);
        tmp.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    unordered_map<char,string> m =  {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    vector<string> ans;
    string tmp;
    if(digits == "") return ans;
    solve(digits,0,tmp,ans,m);
    return ans;
}