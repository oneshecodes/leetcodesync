class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;
        
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            if (currentGas < 0) {
                // If currentGas is negative, we can't start from the current station.
                startIndex = i + 1;
                currentGas = 0;
            }
        }
        
        // If the total amount of gas is less than the total cost, return -1.
        return totalGas < totalCost ? -1 : startIndex;
    }
};
