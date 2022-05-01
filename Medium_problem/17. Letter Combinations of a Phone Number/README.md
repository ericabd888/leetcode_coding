# 17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

<img width="212" alt="image" src="https://user-images.githubusercontent.com/32319856/166137400-15d81b73-1c1f-4c98-93be-d6086a8295c3.png">

**Example 1:**
```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**
```
Input: digits = ""
Output: []
```

**Example 3:**
```
Input: digits = "2"
Output: ["a","b","c"]
```

**Constraints:**
* 0 <= digits.length <= 4
* digits[i] is a digit in the range ['2', '9'].

**IDEAs:**
* DFS

**C++:**
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> value_map = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> total_str;
        for(int i = 0; i < digits.length(); i++){
            total_str.push_back(value_map[digits[i]-50]);
        }
        string cur = "";
        vector<string> ans;
        if(total_str.size() == 0) return {};
        dfs_append(total_str, cur, ans, 0, 0);
        return ans;
        
    }
    void dfs_append(vector<string>& total_str, string& cur, vector<string>& ans,
                    int idx1, int idx2){
        if(cur.length() == total_str.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < total_str[idx1].size(); i++){
            cur.push_back(total_str[idx1][i]);
            dfs_append(total_str, cur, ans, idx1+1, i);
            cur.pop_back();
        }
    }
};
```
