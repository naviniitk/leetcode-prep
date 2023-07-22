// O(n) time and O(n) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 2) return 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        int currLeftMax = height[0], currRightMax = height[n-1];
        for(int i = 0; i < n; i++) {
            currLeftMax = max(height[i], currLeftMax); // Get the max array from left and right, the minimum value of both of the arrays at an index will indicate max height to be filled
            leftMax[i] = currLeftMax;
            currRightMax = max(height[n-i-1], currRightMax);
            rightMax[n-i-1] = currRightMax;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};

// O(n) time and O(1) space

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        
        }
        return water;
    }
};
