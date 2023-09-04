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
    TreeNode* getChildNode(vector<int>& nums, int left, int right) {
        if(left > right)
            return NULL;
        int mid = left + (right -left)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = getChildNode(nums, left, mid - 1);
        curr->right = getChildNode(nums, mid + 1, right);
        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return getChildNode(nums, 0, n - 1);
    }
};
