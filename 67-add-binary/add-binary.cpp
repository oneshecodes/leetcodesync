class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string result;
        
        // Process both strings until both are fully traversed and carry is 0.
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            
            if(i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            // Compute new digit and update carry.
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        
        // The result is computed in reverse order.
        reverse(result.begin(), result.end());
        return result;
    }
};
