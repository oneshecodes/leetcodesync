class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        // 1. Initialize the 'powerSet' to store all the subsets we find. It's like our empty lunchbox where we'll put all the sandwiches.
        List<List<Integer>> powerSet = new ArrayList<>();

        // 2. Get the number of elements in the input array.  How many ingredients do we have?
        int n = nums.length;

        // 3. Calculate the total number of subsets.  For 'n' elements, there are 2^n subsets.
        //    Think of it like this: each element can either be IN or OUT of a subset.  So 2 choices for each element.
        int totalSubsets = 1 << n; // This is the same as Math.pow(2, n), but faster!

        // 4. Iterate through all possible subsets, represented by a 'mask'.
        //    The 'mask' is a binary number. Each bit represents whether an element is in the subset or not.
        for (int mask = 0; mask < totalSubsets; mask++) {

            // 5. Create a new subset for the current mask. It's like grabbing a fresh slice of bread.
            List<Integer> subset = new ArrayList<>();

            // 6. Iterate through each element in the input array.  Checking each ingredient...
            for (int i = 0; i < n; i++) {

                // 7. Check if the i-th bit in the 'mask' is set (i.e., is it a 1?).
                //    If it is, it means the i-th element should be included in the current subset.
                //    Think of it like: "Is this ingredient on the shopping list for this sandwich?"
                if ((mask & (1 << i)) != 0) {

                    // 8. If the i-th bit is set, add the corresponding number to the current subset.
                    //    Adding the ingredient to the sandwich!
                    subset.add(nums[i]);
                }
            }

            // 9. Add the complete subset to the 'powerSet'. Put the sandwich in the lunchbox!
            powerSet.add(subset);
        }

        // 10. Return the 'powerSet' containing all the subsets. Hand over the lunchbox!
        return powerSet;
    }
}