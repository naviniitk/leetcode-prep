class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buyPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            buyPrice = min(buyPrice, prices[i]);
            ans = max(ans, prices[i] - buyPrice);
        }
        return ans;
    }
};
