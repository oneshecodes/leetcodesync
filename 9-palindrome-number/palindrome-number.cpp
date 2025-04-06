class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        // Numbers ending with 0 can't be palindromes unless the number is 0
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even length, x == reversedHalf
        // For odd length, x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
