# 36. Valid Sudoku
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

**Example 1:**<br>
![](https://i.imgur.com/HlcP1xi.png)<br>
```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```
**Example 2:**
```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```
**Constraints:**
* board.length == 9
* board[i].length == 9
* board[i][j] is a digit 1-9 or '.'.

**c++**
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int start, end;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.'){
                    unordered_map<int, int> checkRow, checkCol, checkBox;
                    for(int z = 0; z < 9; z++){
                        if(board[i][z]!='.'){
                            if(checkRow[board[i][z]]) {
                                cout<<i<<" "<<j<<" "<<i<<" "<<z<<endl;
                                return false;
                            }
                            else checkRow[board[i][z]] = 1;     
                        }
                    }
                    for(int z = 0; z < 9; z++){
                        if(board[z][j]!='.'){
                            if(checkCol[board[z][j]]) return false;
                            else checkCol[board[z][j]] = 1;     
                        }
                    }
                    start = i - (i%3);
                    end = j - (j%3);
                    for(int z = start; z <= start+2; z++){
                        for(int x = end; x <= end+2; x++){
                            if(board[z][x]!='.'){

                                if(checkBox[board[z][x]]){
                                    
                                    return false;
                                }
                                else checkBox[board[z][x]] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
```
