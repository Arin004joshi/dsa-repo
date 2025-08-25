class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        int left = 0, right = arr.size() - 1;
        int ans = -1;   // store index of k if found

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == k) {
                ans = mid;       // potential answer
                right = mid - 1; // keep looking left for smaller index
            } 
            else if (arr[mid] < k) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
