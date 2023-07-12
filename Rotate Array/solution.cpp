// O(n) time and O(k) space

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n <= 1)
            return;
        int r = k % n;
        if(r == 0) return;
        vector<int> temp(r, 0);
        for(int j = 0; j < r; j++) {
            temp[j] = nums[n - r + j];
        }
        for(int i = n-1; i >= r; i--) {
            nums[i] = nums[i-r];
        }
        for(int i = 0; i < r; i++) {
            nums[i] = temp[i];
        }
        return;
    }
};

// O(n) time and O(1) space

class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int a =k%v.size();
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin()+a);
        reverse(v.begin()+a,v.end());
    }
};
