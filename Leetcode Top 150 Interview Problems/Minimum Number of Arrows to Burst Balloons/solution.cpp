bool compare(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1])
            return a[0] <= b[0];
        return a[1] <= b[1];
    }

class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int ans = 0;
        int start = 0, end = points.size();
        while(start < end) {
            int left = points[start][1];
            ans++;
            start++;
            while(start < end && points[start][0] <= left) start++;
        }
        return ans;
    }
};
