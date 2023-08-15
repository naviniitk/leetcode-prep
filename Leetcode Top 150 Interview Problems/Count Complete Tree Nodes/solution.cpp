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
    int count(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL) {
            return 1;
        }
        else if(root->left == NULL) {
            return 1 + count(root->right);
        } 
        else if(root->right == NULL) {
            return 1 + count(root->left);
        }
        else {
            return count(root->left) + count(root->right) + 1;
        }
    }

    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return count(root);
    }
};
