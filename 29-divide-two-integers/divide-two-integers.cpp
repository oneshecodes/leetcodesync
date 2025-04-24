class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow: when dividend is INT_MIN and divisor is -1,
        // the quotient would overflow beyond INT_MAX.
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Convert both numbers to long to prevent overflow and work with their absolute values.
        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long quotient = 0;
        
        // Subtract the divisor (multiplied by an appropriate power of 2) from the dividend
        // until the dividend becomes smaller than the divisor.
        while (dvd >= dvs) {
            long temp = dvs, multiple = 1;
            // Double temp and multiple while the dividend is still larger.
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            // Subtract the largest shifted divisor value from dividend.
            dvd -= temp;
            // Add the corresponding multiple to our quotient.
            quotient += multiple;
        }
        
        // Adjust the sign of the quotient.
        // If either dividend or divisor is negative (but not both), the result is negative.
        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;
        
        return quotient;
    }
};
