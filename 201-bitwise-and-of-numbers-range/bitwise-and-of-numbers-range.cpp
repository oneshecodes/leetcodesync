class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        
        // Keep shifting left and right until they become equal
        while (left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        
        // Shift back to the left to restore the common prefix
        return left << shift;
    }
};
