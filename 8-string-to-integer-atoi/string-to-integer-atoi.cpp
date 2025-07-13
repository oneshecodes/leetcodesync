class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int digit;
        int len = s.size();
        int i = 0;
        int sign = 1; //if s is negative we will change to -1 later and * result

          //skip any spaces in the start
        while (i < len && s[i] == ' ') ++i;

        //check for negative
        if (i < len && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            ++i;
        }

        //now begin converting the numbers
        while (i < len && s[i] >= '0' && s[i] <= '9') { 
            int digit = s[i] - '0';
            //check for overflow
            if (result > (INT_MAX - digit) / 10)
                return sign == 1 ? INT_MAX : INT_MIN;

            //multiply current digits by 10 and add next digit to the end to get 100s-10s-1s etc
            result = result * 10 + digit;
            ++i;
        }
        //return result with appropriate sign +/-
        return result * sign;
    }
    
};