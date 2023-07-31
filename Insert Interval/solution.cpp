class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        for(auto x:intervals) {
            if(x[1] < newInterval[0])
                ans.push_back(x);
            else if(x[0] > newInterval[1]) {
                ans.push_back(newInterval); // will come at this place
                newInterval = x; // will keep sliding
            }
            else if(x[0] <= newInterval[1] || x[1] >= newInterval[0]) {
                newInterval[0] = min(x[0], newInterval[0]);
                newInterval[1] = max(x[1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};
