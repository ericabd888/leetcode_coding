# 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

**Example 1:**
```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**
```
Input: n = 1
Output: ["()"]
```

**Constraints:**
* 1 <= n <= 8

**IDEAs:**
* DFS

**C++:**
```cpp=
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur_str = "";
        dfs(ans, n, n, cur_str);
        return ans;
    }
    void dfs(vector<string>& ans, int left, int right, string cur_str){
        if(right < left) {
            cur_str.pop_back();
            return;
        }
        if(left == 0 && right == 0) ans.push_back(cur_str);
        if(left > 0) dfs(ans, left-1, right, cur_str + '(');
        if(right > 0) dfs(ans, left, right-1, cur_str + ')');
    }
};
```
