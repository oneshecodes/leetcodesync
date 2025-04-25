class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare mid element with its right neighbor
            if (nums[mid] > nums[mid + 1]) {
                // Peak is on the left half (including mid)
                right = mid;
            } else {
                // Peak is on the right half (excluding mid)
                left = mid + 1;
            }
        }

        return left; // or right (both are equal at this point)
    }
};
