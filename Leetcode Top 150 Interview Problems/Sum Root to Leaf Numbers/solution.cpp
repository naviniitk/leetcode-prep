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
    int traverse(TreeNode* root, int sum) {
        if(root == NULL) return sum;
        if(root->right == NULL) return traverse(root->left, sum*10 + root->val);
        if(root->left == NULL) return traverse(root->right, sum*10 + root->val);
        return traverse(root->left, sum*10 + root->val) + traverse(root->right, sum*10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return traverse(root, sum);
    }
};
