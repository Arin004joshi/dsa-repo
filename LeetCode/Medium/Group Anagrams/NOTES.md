
          # Group Anagrams

          **Summary:** The code uses ArrayLists and boolean arrays to group anagrams.  It iterates through the input array of strings, using a nested loop to compare each string with the others.  The `isAnagram` helper function, utilizing character arrays and sorting, determines if two strings are anagrams.  Strings identified as anagrams are grouped together in a list of lists.

          - Time Complexity: O(n*m*log(m)) where n is the length of the input array and m is the maximum length of a string. The nested loops contribute O(n^2), and sorting each string in `isAnagram` adds O(m*log(m)) for each comparison.
          - Space Complexity: O(n*m) where n is the number of strings and m is the maximum length of a string.  The space is dominated by the result list, which can grow up to the size of the input array if each string is unique. The auxiliary arrays used in `isAnagram` are of length m
          