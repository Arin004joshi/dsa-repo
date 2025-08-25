class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        
        // Transform string with separators to handle even-length palindromes
        StringBuilder sb = new StringBuilder("^");
        for (int i = 0; i < s.length(); i++) {
            sb.append("#").append(s.charAt(i));
        }
        sb.append("#$");
        
        char[] arr = sb.toString().toCharArray();
        int n = arr.length;
        int[] p = new int[n]; // array to hold palindrome radius
        int center = 0, right = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;
            
            if (i < right) {
                p[i] = Math.min(right - i, p[mirror]);
            }
            
            // attempt to expand palindrome centered at i
            while (arr[i + (1 + p[i])] == arr[i - (1 + p[i])]) {
                p[i]++;
            }
            
            // update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
        
        // find longest palindrome
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }
        
        int start = (centerIndex - maxLen) / 2; // map back to original string
        return s.substring(start, start + maxLen);
    }
}
