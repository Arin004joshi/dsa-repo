
          # Group Anagrams

          **Summary:** The code uses ArrayLists and boolean arrays to group anagrams. It iterates through the input array of strings, using a nested loop to compare each string with the rest.  The `isAnagram` helper function efficiently checks for anagrams by sorting the character arrays of two strings and comparing them. A boolean array tracks already-processed strings to avoid redundant comparisons.

          - Time Complexity: O(n*m*logm), where n is the number of strings and m is the maximum length of a string. The nested loops contribute O(n^2) complexity. Sorting each pair of strings within the inner loop takes O(m log m) time, leading to a total time complexity of O(n*m*logm).
          - Space Complexity: O(n*m) in the worst case where n is the number of strings and m is the maximum length of a string. This is because in the worst-case scenario (all strings are anagrams), the result list will store all the strings, resulting in a space complexity proportional to the total length of all input strings.  The auxiliary space used by sorting (in `isAnagram`) and the boolean array `visited` are also considered here.
          