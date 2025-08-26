
          # Group Anagrams

          **Summary:** The algorithm utilizes an ArrayList of ArrayLists of Strings to store the grouped anagrams and a boolean array to track visited strings. It iterates through the input array of strings. For each unvisited string, it creates a group, adds the string to the group, marks it as visited, and then checks the remaining strings for anagrams using a helper function. Anagrams are added to the group and marked as visited. Finally, the list of groups is returned.

          - Time Complexity: O(m*n*log m), where n is the number of strings and m is the maximum length of a string. The nested loops contribute O(n^2), and sorting each string within isAnagram() takes O(m log m) time.
          - Space Complexity: O(n*m), where n is the number of strings and m is the maximum length of a string. The space is primarily used to store the result list which can hold up to n strings, each of length m in the worst case.
          