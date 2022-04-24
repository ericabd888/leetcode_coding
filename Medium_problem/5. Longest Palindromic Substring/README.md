# 5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

**Example 1:**
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```
**Example 2:**
```
Input: s = "cbbd"
Output: "bb"
```
**Constraints:**
* 1 <= s.length <= 1000
* s consist of only digits and English letters.

**IDEAs:**
* 使用DP 畫表格來解

* c++:
```
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(); 
        int j = 0;
        int maxbegin = 0, maxlen = 1;
        bool pal_table[1000][1000] = {false};
        for(int i = 0; i < n; i++){
            pal_table[i][i] = true;
        }
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                pal_table[i][i+1] = true;
                maxbegin = i;
                maxlen = 2;
            }
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                j = i + len - 1;
                if(s[i] == s[j] && pal_table[i+1][j-1]){
                    pal_table[i][j] = true;
                    maxlen = len;
                    maxbegin = i;
                }
            }
        }
        return s.substr(maxbegin, maxlen);
    }
};
```
