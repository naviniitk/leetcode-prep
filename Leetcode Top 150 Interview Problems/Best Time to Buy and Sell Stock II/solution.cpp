class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit = 0;
        int ans = 0;
        int temp = prices[0];
        for(int i = 0; i < prices.size(); i++) {
            currProfit = prices[i] - temp;
            if(currProfit > 0) {
                ans += currProfit;
            }
            temp = prices[i];
        }
        return ans;
    }
};
