#include <vector>
#include <algorithm> // For std::swap (though a manual swap is fine too)

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // Initialize the 'slow' pointer (k) to track the position 
        // for the next element that is *not* equal to val.
        int k = 0; 
        
        // The 'fast' pointer (i) iterates through all elements of the array.
        for (int i = 0; i < nums.size(); ++i) {
            // Check if the current element should be kept (i.e., it's NOT the value to remove)
            if (nums[i] != val) {
                // If the element should be kept, move it to the position k.
                // This effectively overwrites any elements equal to 'val' that
                // were previously copied to position k.
                nums[k] = nums[i];
                
                // Increment k to prepare for the next element to be kept.
                k++;
            }
            // If nums[i] == val, we simply skip it (don't increment k), 
            // and the fast pointer i moves on, leaving the element at nums[k]
            // to be overwritten by a later non-val element.
        }
        
        // 'k' now represents the number of elements that are not equal to 'val', 
        // which is the new length of the array.
        return k;
    }
};