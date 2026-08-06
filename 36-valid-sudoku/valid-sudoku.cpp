class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';     // 0 to 8
                int box = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || cols[j][num] || boxes[box][num])
                    return false;

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};


/*
⏱️ Time Complexity: O(1)

Reason:
- A Sudoku board always has a fixed size of 9 × 9.
- We traverse all 81 cells exactly once.
- Since the board size never changes, the running time is constant.

💾 Space Complexity: O(1)

Reason:
- Three fixed-size boolean arrays (9 × 9) are used to track rows, columns, and 3 × 3 boxes.
- Their size is constant and does not depend on the input.
*/