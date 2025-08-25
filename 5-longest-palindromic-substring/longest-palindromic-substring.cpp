#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        // Transform string: add separators to handle even/odd uniformly
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            // expand around i
            while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                p[i]++;

            // update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // Find the maximum length palindrome
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2; // map back to original string
        return s.substr(start, maxLen);
    }
};
