1. Problem can be relatable to LIS, Just instead of comparning A[i],A[j] we need to compare two strings.
2. compare(s1,s2) => Can we form string s2 by inserting 1 char in s1.

Approach : Use LIS code

#CODE:
bool checkPossible(string &s1, string &s2) {
    if(s1.size() != s2.size()+1) return false;
    int first = 0, second=0;
    while(first < s1.size()) {
        if(second < s2.size() && s1[first] == s2[second]) {
            first++; second++;
        } else {
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false;
}
bool comp(string &s1, string &s2) {
    return s1.size() < s2.size();
}
int longestStrChain(vector<string>& words) {
    // sort by length
    sort(words.begin(), words.end(),comp);
    int n = words.size();
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i=0;i<n;++i) {
        for(int prevIdx=0;prevIdx<i;++prevIdx) {
            if(checkPossible(words[i],words[prevIdx]) && dp[prevIdx]+1 > dp[i]) {
                dp[i] = 1 + dp[prevIdx];
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
        }
    }
    return maxi;
}
=> Time Complexity = O(n^2) * O(length of chain)
=> Space Complexity = O(n)