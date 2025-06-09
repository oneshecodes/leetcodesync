class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int curr = 0, ans = 0 , n = nums.length;
        if(n < 3) return 0;
        for(int i = 1; i < n-1; i++){
            if(nums[i] - nums[i-1] == nums[i+1] - nums[i]){
                curr++;
                ans += curr;
            }else{
                curr = 0;
            }
        }
        return ans;
    }
}