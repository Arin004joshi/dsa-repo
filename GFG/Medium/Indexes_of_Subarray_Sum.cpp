class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int start = 0;
        long long sum = 0; // use long long to avoid overflow

        for (int end = 0; end < n; end++) {
            sum += arr[end];

            // shrink the window if sum exceeds target
            while (sum > target && start <= end) {
                sum -= arr[start];
                start++;
            }

            // check if sum matches
            if (sum == target) {
                return {start + 1, end + 1}; // 1-based indices
            }
        }
        return {-1}; // if no subarray found
    }
};
