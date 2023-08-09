class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0;
        int currSum = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            while(currSum >= target) {
                ans = min(ans, i - j + 1);
                currSum -= nums[j];
                j++; // Sliding window
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
