# 48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
**Example 1:**
![image](https://user-images.githubusercontent.com/32319856/165879662-4960f0af-fd8e-4b53-b50e-2061e5e56aed.png =250x)
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```
**Example 2:**
![image](https://user-images.githubusercontent.com/32319856/165879748-5a3dff77-849c-4772-a812-fd3f33485497.png =250x)

```
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```
**Constraints:**
* n == matrix.length == matrix[i].length
* 1 <= n <= 20
* -1000 <= matrix[i][j] <= 1000

**IDEAs:**

**C++**
```cpp
class Solution {
public:
    
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int row = 0; row < n/2; row++)
        {
            int cur_size = n - 2*row;

            for(int col = row; col < cur_size-1+row; col++)
            {
                swap(matrix[row][col], matrix[n-1-col][row]);
                swap(matrix[n-1-col][row], matrix[n-1-row][n-col-1]);
                swap(matrix[n-1-row][n-col-1], matrix[col][n-1-row]);
                cout<<"cur row: "<<row<<endl<<endl;
                for ( const auto &row : matrix )
                {
                    for ( const auto &s : row ) cout << s << ' ';
                    cout << std::endl;
                }
                cout<<endl<<endl;
            }

        }

    }
};
```
