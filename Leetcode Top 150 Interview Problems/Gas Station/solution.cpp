class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int currGas = 0;
        int totalGas = 0, totalCost = 0;
        for(int j = 0; j < gas.size(); j++) {
            totalGas += gas[j];
            totalCost += cost[j];

            currGas += gas[j] - cost[j];
            if(currGas < 0) {
                i = j + 1;
                currGas = 0;
            }
        }
        return totalGas < totalCost ? -1 : i;
    }
};
