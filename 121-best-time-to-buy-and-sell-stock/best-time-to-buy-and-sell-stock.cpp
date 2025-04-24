class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // Initialize the minimum price to the maximum possible value
        int maxProfit = 0;       // Initialize the maximum profit to 0
        
        for (int price : prices) {
            // Update the minimum price encountered so far
            minPrice = min(minPrice, price);
            
            // Calculate the potential profit for the current price
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};
