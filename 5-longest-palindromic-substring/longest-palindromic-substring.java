class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n < 2)
            return s;

        // Transform input string with separators to handle even palindromes
        char[] t = new char[2 * n + 3];
        t[0] = '^';
        for (int i = 0; i < n; i++) {
            t[2 * i + 1] = '#';
            t[2 * i + 2] = s.charAt(i);
        }
        t[2 * n + 1] = '#';
        t[2 * n + 2] = '$';

        int[] p = new int[t.length];
        int center = 0, right = 0;
        int maxLen = 0, centerIndex = 0;

        for (int i = 1; i < t.length - 1; i++) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = Math.min(right - i, p[mirror]);

            // expand around i
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substring(start, start + maxLen);
    }
}
