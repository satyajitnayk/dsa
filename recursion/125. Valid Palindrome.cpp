A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

**LEARNING: iswalnum(char c) checks if a chr is alphanumeric or not!

Time O(n) & space O(1)
## CODE:
bool isPalindrome(string s) {
  int i=0, j=s.length()-1;
  while(i<j) {
      if(i>=j) return true;
      if(!iswalnum(s[i])){
          i++;
      } else if(!iswalnum(s[j])) { 
          j--;
      } else if(tolower(s[i])==tolower(s[j])){
          i++;j--;
      } else return false;
  }
  return true;    
}