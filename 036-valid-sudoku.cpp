#define LEETCODE_36

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool used_row[9][9] = {false};
        bool used_col[9][9] = {false};
        bool used_box[9][9] = {false};

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = (i/3)*3 + j/3;
                    if (used_row[i][num] || used_col[j][num] || used_box[k][num])
                        return false;
                    used_row[i][num] = true;
                    used_col[j][num] = true;
                    used_box[k][num] = true;
                }
            }
        }
        return true;
    }
};
