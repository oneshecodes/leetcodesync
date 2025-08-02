class Solution {
    public int removeDuplicates(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int k =0;
        for(int i=0; i<nums.length; i++){
            map.put(nums[i], map.getOrDefault(nums[i],0) +1);
            if(map.get(nums[i])<= 2){
                nums [k] = nums[i];
                k++;
            }
        }
        return k;
    }
}