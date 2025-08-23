class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        int i = 0, j = 0, k = 0;
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        vector<int> result;

        while (i < n1 && j < n2 && k < n3) {
            // If all three elements are equal
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                result.push_back(arr1[i]);

                int val = arr1[i];
                while (i < n1 && arr1[i] == val) i++; // skip duplicates
                while (j < n2 && arr2[j] == val) j++;
                while (k < n3 && arr3[k] == val) k++;
            }
            else {
                // Find the smallest among arr1[i], arr2[j], arr3[k]
                int mn = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == mn) {
                    int val = arr1[i];
                    while (i < n1 && arr1[i] == val) i++; // skip duplicates
                } else if (arr2[j] == mn) {
                    int val = arr2[j];
                    while (j < n2 && arr2[j] == val) j++;
                } else {
                    int val = arr3[k];
                    while (k < n3 && arr3[k] == val) k++;
                }
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};
