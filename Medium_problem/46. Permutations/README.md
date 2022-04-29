# 46. Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
**Example 1:**
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
**Example 2:**
```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```
**Example 3:**
```
Input: nums = [1]
Output: [[1]]
```

**Constraints:**
* 1 <= nums.length <= 6
* -10 <= nums[i] <= 10
* All the integers of nums are unique.

**IDEAs:**
* backtracking 演算法
<img src=https://i.imgur.com/aLEZl78.png, width=250>

**C++**
```cpp
// solution 1
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> ans;
        permuteDFS(num, 0, ans);
        return ans;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& ans) {
        if (start >= num.size()) ans.push_back(num);
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, ans);
            swap(num[start], num[i]);
        }
    }
};

// solution 2
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> viewed(nums.size(), false);
        backtracking(nums, ans, temp, viewed);
        return ans;
        
    }
    void backtracking(vector<int>& nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &viewed){
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(viewed[i]) continue;
            temp.push_back(nums[i]);
            viewed[i] = true;
            backtracking(nums, ans, temp, viewed);
            temp.pop_back();
            viewed[i] = false;
        }
    }
};
```
