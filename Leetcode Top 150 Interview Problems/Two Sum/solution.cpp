// O(n^2) time and O(1) space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j;
        vector<int> ans;
        for(; i < nums.size() -1; i++) {
            for(j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

// O(n) time and O(n) space

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};
