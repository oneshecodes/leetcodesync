class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += (n & 1); // Add 1 if the last bit is set
            n >>= 1;          // Right shift to check next bit
        }
        return count;
    }
};
