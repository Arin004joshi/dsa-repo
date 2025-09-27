class Solution {
    public boolean isPalindrome(int x) {
        // Condition 1: If x is negative, it can't be a palindrome (e.g., -121).
        // Condition 2: If the number ends in 0 (x % 10 == 0) and is not 0 itself, 
        // it can't be a palindrome (e.g., 10, 200). 
        // Only 0 is a palindrome that ends in 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedNumber = 0;
        
        // Loop to build the reversed number.
        // We stop when reversedNumber becomes greater than or equal to x.
        // This means we've processed half of the digits.
        while (x > reversedNumber) {
            int digit = x % 10;
            reversedNumber = reversedNumber * 10 + digit;
            x /= 10;
        }

        // A palindrome check requires comparing the original number's first half (x)
        // with the reversed number's first half (reversedNumber).
        
        // Case 1: The number has an even number of digits (e.g., 1221).
        // The loop will stop when x == reversedNumber (12 == 12).
        // We return x == reversedNumber.
        
        // Case 2: The number has an odd number of digits (e.g., 121).
        // The loop will stop when x < reversedNumber (1 < 12). 
        // The middle digit is now the last digit of reversedNumber (2).
        // To ignore the middle digit, we divide reversedNumber by 10 (12 / 10 = 1).
        // We return x == reversedNumber / 10.
        
        return x == reversedNumber || x == reversedNumber / 10;
    }
}