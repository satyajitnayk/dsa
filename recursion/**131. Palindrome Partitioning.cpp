Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s.
A palindrome string is a string that reads the same backward as forward.

##Approach:
1. Try to parition at each places 
2. If we can successfully parition string s at end => we are able to divide the string into palindromes.

##CODE:
bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if(s[start++] != s[end--]) return false;
    }
    return true;
}
void solve(int index, string &s,  vector<string> &ss, vector<vector<string>> &ans) {
    if(index == s.size()) {
        ans.push_back(ss);
        return;
    }
    for(int i=index;i<s.size();++i) {
        if(isPalindrome(s,index, i)) {
            ss.push_back(s.substr(index, i-index+1));
            solve(i+1,s,ss,ans);
            ss.pop_back();
        }
    } 
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> ss;
    solve(0,s,ss,ans);
    return ans;
}