class Solution {
public:
    int strStr(string haystack, string needle) {
        // If needle is empty, return 0 (as per problem convention)
        if (needle.empty()) return 0;
        
        int n = haystack.size();
        int m = needle.size();
        
        // Loop through haystack until there's no room left for needle
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at i matches needle
            if (haystack.substr(i, m) == needle)
                return i;
        }
        
        // If needle is not found, return -1
        return -1;
    }
};
