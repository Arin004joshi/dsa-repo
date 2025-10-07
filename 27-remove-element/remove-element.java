class Solution {
    public int removeElement(int[] nums, int val) {
        // 'k' will be the count of elements not equal to 'val' 
        // and also the index where the next non-'val' element should be placed.
        int k = 0; 
        
        // Iterate through the array with pointer 'i'
        for (int i = 0; i < nums.length; i++) {
            // Check if the current element is NOT the value to remove
            if (nums[i] != val) {
                // If it's a desired element, place it at the 'k' position
                nums[k] = nums[i];
                // Increment 'k' to point to the next available spot
                k++;
            }
            // If nums[i] == val, we simply skip it. The element at nums[i] is effectively
            // "removed" from the first 'k' portion of the array.
        }
        
        // 'k' is the number of elements in nums which are not equal to val
        return k;
    }
}