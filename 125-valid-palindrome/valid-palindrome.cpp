class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Check if the characters at left and right pointers are the same (case insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move pointers towards the center
            left++;
            right--;
        }
        
        return true;
    }
};
