You are given an array of strings arr. A string s is formed by the concatenation 
of a subsequence of arr that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by 
deleting some or no elements without changing the order of the remaining elements.

Approach :

// function responsible for check if there will be any repetition
bool checkNoRepetition(vector<bool>& selected, string& s) {
    vector<bool> selfcheck(26,false);
    // if char repeats in s then return true
    for(char c: s) {
        if(selfcheck[c-'a']) return false;
        selfcheck[c-'a'] = true;
    }
    for(char c: s) {
        // if any of the char of s already selected 
        // previously that means repetition
        if(selected[c-'a']) return false;
    }
    return true;
}
// len store max string len so far
int solve(int i,vector<string> &arr,vector<bool> &selected,int len) {
    // BC
    if(i == arr.size()) return len;
    
    string s = arr[i];
    if(checkNoRepetition(selected, s)){
        // no repetition found
        // 2 choices use the string s or leave it
        
        // choose it
        for(char c: s) {
            // mark selected chars to true
            selected[c-'a'] = true;
        }
        // increment len by length of string s
        len += s.size();
        // ask recursion to do subtask
        int op1 = solve(i+1,arr,selected,len);
        
        // leave it
        // redo everything we have done
        for(char c: s) {
            // mark selected chars to true
            selected[c-'a'] = false;
        }
        len -= s.size();
        int op2 = solve(i+1,arr,selected,len); 
        
        return max(op1, op2);
    } else {
        // 1 choice => skip string s
        return solve(i+1,arr,selected,len);
    }
}
int maxLength(vector<string>& arr) {
    vector<bool> selected(26,false);
    return solve(0,arr,selected,0);
}