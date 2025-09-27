class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        // Iterate from the least significant digit (right) to the most significant (left)
        for (int i = digits.size() - 1; i >= 0; --i) {
            // Case 1: Current digit is not 9
            if (digits[i] < 9) {
                // Increment the digit
                digits[i]++;
                // No carry-over, so we are done. Return the modified array.
                return digits;
            } 
            // Case 2: Current digit is 9
            else {
                // Set the current digit to 0 and continue the loop to carry the 1
                digits[i] = 0;
            }
        }
        
        // If the loop completes, it means all digits were 9s (e.g., [9, 9, 9]).
        // The resulting integer requires an extra leading digit (e.g., 1, 0, 0, 0).
        
        // Insert a new leading digit '1' at the beginning (index 0).
        digits.insert(digits.begin(), 1);
        
        // Return the resulting array.
        return digits;
    }
};