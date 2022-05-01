# 98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
 

**Example 1:**<br>
<img width="307" alt="image" src="https://user-images.githubusercontent.com/32319856/166155124-e367fcbc-f59c-468c-8cb7-5f4c8c46b5c2.png">
```
Input: root = [2,1,3]
Output: true
```

**Example 2:**<br>
<img width="431" alt="image" src="https://user-images.githubusercontent.com/32319856/166155150-98b56d57-86c9-44c0-a435-92155c01a86b.png">
```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```
**Constraints:**
* The number of nodes in the tree is in the range [1, 104].
* -231 <= Node.val <= 231 - 1

**IDEAs:**
* Just Follow The BST Definition.
* Recursive

**C++:**
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!(left_small(root, root->left) && right_big(root, root->right))) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
    bool left_small(TreeNode* root, TreeNode* left_tree){
        if(!left_tree) return true;
        if(root->val <= left_tree->val) return false;
        return left_small(root, left_tree->left) && left_small(root, left_tree->right);
    }
    bool right_big(TreeNode* root, TreeNode* right_tree){
        if(!right_tree) return true;
        if(root->val >= right_tree->val) return false;
        return right_big(root, right_tree->left) && right_big(root, right_tree->right);  
    }
};
```

