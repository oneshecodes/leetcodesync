class Solution {
public:
    bool isPowerOfTwo(int n) {
        // n must be greater than 0 and (n & (n - 1)) must be 0
        return n > 0 && (n & (n - 1)) == 0;
    }
};
