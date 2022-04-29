# 74. Search a 2D Matrix
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

**Example 1:**<br>
<img src=https://user-images.githubusercontent.com/32319856/165880688-f5da0a2b-a6ad-4795-b0c8-a08740cf3071.png width=300>

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**<br>
<img src=https://user-images.githubusercontent.com/32319856/165880769-c7485536-0073-4fd0-b241-98f2a8929ea7.png width=300>
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Constraints:**
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 100
* -104 <= matrix[i][j], target <= 104

**IDEAs:**

**C++:**
```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = 0;
        while(true){
            if(row >= m) {
                row--;
                break;
            }
            if(target <= matrix[row][n-1]) break;
            else row++;
        }
        for(int i = matrix[0].size()-1; i>=0; i--){
            if(target == matrix[row][i]) return true;
        }
        return false;
    }
};
```
