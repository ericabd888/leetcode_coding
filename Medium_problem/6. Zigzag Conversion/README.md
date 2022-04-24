# 6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
```
string convert(string s, int numRows);
```
**Example 1:**
```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
```
**Example 2:**
```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```
**Example 3:**
```
Input: s = "A", numRows = 1
Output: "A"
```
**Constraints:**
* 1 <= s.length <= 1000
* s consists of English letters (lower-case and upper-case), ',' and '.'.
* 1 <= numRows <= 1000
**c++**
```
class Solution {
public:
    struct test
    {
        int x, y, z;
    };
    string convert(string s, int numRows) {
        vector<test> pos;
        string ans;
        bool now = false;
        int row = 0, col = 0, count = 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(numRows == 1)
            {
                if(now)
                {
                    pos.push_back({row, col, i});
                    col ++;
                }
                else
                {
                    pos.push_back({row, col, i});
                    col ++;
                }
            }
            else
            {
                if(row == (numRows - 1) || row == 0) 
                {
                    now = !(now);
                }
                if(now)
                {
                    pos.push_back({row, col, i});
                    row ++;
                }
                else
                {
                    pos.push_back({row, col, i});
                    row --;
                    col ++;
                }
            }
        }
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < pos.size(); j++)
            {
                if(pos[j].x == i) ans.push_back(s[pos[j].z]);
            }
        }
        return ans;
    }
};
```
