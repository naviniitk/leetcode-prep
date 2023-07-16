class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i] + i, nums[i - 1]); // Will create increasing array
        }

        int index = 0, ans = 0;
        while(index < nums.size() - 1) {
            ans++;
            index = nums[index];
        }
        return ans;
    }
};
