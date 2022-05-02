# 94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

**Example 1:**<br>
<img src=https://user-images.githubusercontent.com/32319856/165881795-d9f558ad-b0c0-49b5-a128-32a0912a9efa.png width=150>
```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**Example 2:**
```
Input: root = []
Output: []
```

**Example 3:**
```
Input: root = [1]
Output: [1]
```

**Constraints:**
* The number of nodes in the tree is in the range [0, 100].
* -100 <= Node.val <= 100

**Follow up:** Recursive solution is trivial, could you do it iteratively?

**IDEAs:**

**C++:**
```cpp
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {    
    vector<int> ans;
    inorder(root, ans);
    return ans;
  }
  void inorder(TreeNode* root, vector<int>& ans) {
    if (root == null) return;
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);    
  }
};
```
