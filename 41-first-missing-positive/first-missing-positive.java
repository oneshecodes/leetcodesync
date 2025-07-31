class Solution {
    public int firstMissingPositive(int[] nums) {
         Set<Integer> list=new HashSet<>();
         for(int num:nums){
            if(num>0){
                list.add(num);
            }
         }
         
         for(int i=1;i<=list.size()+1;i++){
            if(!list.contains(i)){
                return i;
            }
         }
         return -1;
    }
}