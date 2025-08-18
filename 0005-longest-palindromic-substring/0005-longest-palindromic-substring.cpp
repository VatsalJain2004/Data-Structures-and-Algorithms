class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if(n <= 1) {
      return s;
    }

    string maxPal = "";
    int maxLen = 0;
    for(int i = 0; i < n; i++) {

      // Odd Len Pal Identifier and Checker
      int left = i, right = i;
      while(left >= 0 && right < n && s[left] == s[right]) {
        if(right-left+1 > maxLen) {
          maxLen = right-left+1;
          maxPal = s.substr(left, maxLen);
        }
        left--;
        right++;
      }
      
      // Even Len Pal Identifier and Checker
      left = i, right = i+1;
      while(left >= 0 && right < n && s[left] == s[right]) {
        if(right-left+1 > maxLen) {
          maxLen = right-left+1;
          maxPal = s.substr(left, maxLen);
        }
        left--;
        right++;
      }    
    }
    return maxPal;
  }
};