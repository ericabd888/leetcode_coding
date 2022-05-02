# 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

**Example 1:**<br>
<img width="251" alt="image" src="https://user-images.githubusercontent.com/32319856/166195256-c0a09451-463e-4d3f-9280-921c9caff314.png">
```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```
**Example 2:**
```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**
* m == grid.length
* n == grid[i].length
* 1 <= m, n <= 200
* 0 <= grid[i][j] <= 100

**IDEAs:**
* DP, draw table to compute each condition.

**C++:**
```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> table(row+1, vector<int>(col+1, -1));
        table[0][1] = 0;
        for(int i = 1; i < row+1; i++){
            for(int j = 1; j < col+1; j++){
                int up_value = (table[i-1][j] == -1) ? INT_MAX : table[i-1][j];
                int left_value = (table[i][j-1] == -1) ? INT_MAX : table[i][j-1];
                table[i][j] = min(up_value, left_value) + grid[i-1][j-1];
            }
        }
        return table[row][col];
    }
};
```
