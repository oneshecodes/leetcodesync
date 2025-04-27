#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        
        while (n != 1) {
            if (seen.count(n)) {
                return false;  // Cycle detected
            }
            seen.insert(n);
            
            // Calculate the sum of squares of digits
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        
        return true;  // If we reach 1, it's a happy number
    }
};
