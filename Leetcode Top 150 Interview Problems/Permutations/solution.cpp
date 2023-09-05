class Solution {
public:
    void swap(vector<int>& nums, int i, int idx) {
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
    }

    void createPermutation(vector<vector<int>>& ans, vector<int> nums, int idx) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); i++) {
            swap(nums, i, idx);
            createPermutation(ans, nums, idx + 1);
            swap(nums, i, idx);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        createPermutation(ans, nums, 0);
        return ans;
    }
};
