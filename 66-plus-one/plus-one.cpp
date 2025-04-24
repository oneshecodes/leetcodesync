class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;  // start with the 'one' we need to add
        
        // Process the digits from least significant to most significant.
        for (int i = n - 1; i >= 0 && carry; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        // If there's a carry remaining, insert it at the front.
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        
        return digits;
    }
};
