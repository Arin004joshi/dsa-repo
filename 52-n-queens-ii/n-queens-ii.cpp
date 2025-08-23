class Solution {
public:
    int totalNQueens(int n) {
        // sets to track attacked columns and diagonals
        unordered_set<int> cols, diag1, diag2;
        int count = 0;

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                count++;
                return;
            }

            for (int col = 0; col < n; col++) {
                if (cols.count(col) || diag1.count(row - col) ||
                    diag2.count(row + col))
                    continue;

                // place queen
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);

                backtrack(row + 1);

                // remove queen (backtrack)
                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
            }
        };

        backtrack(0);
        return count;
    }
};
