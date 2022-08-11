Given two strings s and p, return an array of all the start indices of p"'"s anagrams in s. 
You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Approach 1: BF

Approach 2: Sliding window + hashmap

-> create a map & store freq of chars of substring 
-> Keep count of distinct chars in a variable.
-> Now slide window & do the following operation: 
  "abcdefghijklmnopq"
   i     j

-> m[s[i]]++; => if(m[s[i]] == 1) count++;
-> m[s[j]]--; => if(m[s[j]] == 0) count--;

-> The above 2 operations are done to avoid iterating over the map in each iteration.
-> Time O(n) & space O(n) for the map.

CODE:

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    unordered_map<char, int> m;
    int k = p.size(); // window size
    for(auto c:p) m[c]++;
    int count = m.size();
    int i=0,j=0;
    while(j<s.size()) {
        m[s[j]]--;
        if(m[s[j]]==0) count--;
        if(j-i+1 == k) {
            if(count == 0) ans.push_back(i);
            m[s[i]]++;
            if(m[s[i]] == 1) count++;
            i++; 
        }
        j++;
    }
    return ans;
}