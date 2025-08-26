
          # Group Anagrams

          **Summary:** The algorithm uses an ArrayList of ArrayLists of Strings to store the grouped anagrams and a boolean array to track visited strings. It iterates through the input array, for each unvisited string, it forms a group of anagrams by comparing it with subsequent strings using a helper function 'isAnagram' that checks if two strings are anagrams by sorting their characters and comparing. Finally, it returns the list of anagram groups.

          - Time Complexity: O(N*K*logK), where N is the number of strings and K is the maximum length of a string. This is because sorting each string takes O(K*logK) time, and we potentially sort each string once.
          - Space Complexity: O(N*K) in the worst case, where N is the number of strings and K is the maximum length of a string. This is because in the worst-case scenario (all strings are anagrams), we store all strings in a single list.
          