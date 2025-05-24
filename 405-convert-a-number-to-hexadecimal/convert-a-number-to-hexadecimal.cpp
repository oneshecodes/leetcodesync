class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string ans = "";
        unsigned int nums = num;
        string hex = "0123456789abcdef";
        while(nums){
            ans = hex[nums % 16] + ans;
            nums /= 16;
        }
        return ans;
    }
};