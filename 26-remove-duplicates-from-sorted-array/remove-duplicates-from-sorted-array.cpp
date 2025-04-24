class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Pointer i will be used to track the position for unique elements.
        int i = 0;
        
        // Start with the second element and compare it with the last unique element found.
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        
        // The number of unique elements is i+1
        return i + 1;
    }
};
