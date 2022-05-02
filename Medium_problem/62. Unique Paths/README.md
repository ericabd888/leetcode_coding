# 62. Unique Paths
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

**Example 1:**<br>
<img width="405" alt="image" src="https://user-images.githubusercontent.com/32319856/166190637-8ebd5b6e-72f6-47d0-8bc6-f781a1065c4a.png">
```
Input: m = 3, n = 7
Output: 28
```
**Example 2:**
```
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Constraints:**
* 1 <= m, n <= 100

**IDEAs:**
* DP, draw table

**C++:**
```cpp
class Solution {    
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        table[0][1] = 1;
        for(int j = 1; j < n+1; j++){
            for(int i = 1; i < m+1; i++){
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
        return table[m][n];
    }
};
```
