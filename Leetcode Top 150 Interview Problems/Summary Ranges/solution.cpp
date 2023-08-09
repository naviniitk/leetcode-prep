class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
            return {};
        vector<string> ans;
        int start = nums[0], curr = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == curr + 1) {
                curr = nums[i];
            } else {
                if(curr == start)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(curr));
                start = nums[i];
                curr = nums[i];
            }
        }
        if(curr == start)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(curr));
        return ans;
    }
};
