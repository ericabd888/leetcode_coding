# 12. Integer to Roman
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
```
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

* I can be placed before V (5) and X (10) to make 4 and 9. 
* X can be placed before L (50) and C (100) to make 40 and 90. 
* C can be placed before D (500) and M (1000) to make 400 and 900.

Given an integer, convert it to a roman numeral.

**Example 1:**
```
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
```
**Example 2:**
```
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
```
**Example 3:**
```
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

**Constraints:**
* 1 <= num <= 3999

**IDEAs:**
* Write down all posible value, and then subtract it.

**C++:**
```cpp
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> table;
        table.push_back(make_pair(1000, "M"));
        table.push_back(make_pair(900, "CM"));
        table.push_back(make_pair(500, "D"));
        table.push_back(make_pair(400, "CD"));
        table.push_back(make_pair(100, "C"));
        table.push_back(make_pair(90, "XC"));
        table.push_back(make_pair(50, "L"));
        table.push_back(make_pair(40, "XL"));
        table.push_back(make_pair(10, "X"));
        table.push_back(make_pair(9, "IX"));
        table.push_back(make_pair(5, "V"));
        table.push_back(make_pair(4, "IV"));
        table.push_back(make_pair(1, "I"));
        int idx = 0;
        int t_size = table.size();
        string ans = "";
        while(idx < t_size){
            if(table[idx].first <= num){
                num -= table[idx].first;
                ans += table[idx].second;
            }
            else{
                idx++;
            }
        }
        return ans;
    }
};
```
