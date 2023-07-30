class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int ans = 0;
        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currNum = num;
                int currMax = 1;
                while(set.find(currNum+1) != set.end()){
                    currNum++;
                    currMax++;
                }
                ans = max(ans, currMax);
            }
        }
        return ans;
    }
};
