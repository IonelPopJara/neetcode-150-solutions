// @leet start
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    // 0 means that the element is not present, the indexes represent the numbers
    // so for example, if 7 is already in the a specific row, it would be
    // rows[r][7];
    // rows[row number][number]
    int rows[9][9] = { 0 };
    int cols[9][9] = { 0 };
    int subgrids[9][9] = { 0 };

    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardColSize[row]; col++) {
            // If the current cell is empty, we skip it
            if (board[row][col] == '.') {
                continue;
            }

            // Otherwise, we check if it's already in the same column or row
            int currentNumber = board[row][col] - '0';
            if (rows[row][currentNumber - 1] != 0
                || cols[col][currentNumber - 1] != 0
                || subgrids[(row / 3) * 3 + col / 3][currentNumber - 1] != 0) {
                return false;
            }

            // Add the number to the columns, rows, and 3x3
            rows[row][currentNumber - 1] = 1;
            cols[col][currentNumber - 1] = 1;
            subgrids[(row / 3) * 3 + col / 3][currentNumber - 1] = 1;
        }
    }

    return true;
}
// @leet end
