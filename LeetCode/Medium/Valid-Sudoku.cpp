// map, O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 0: row, 1: col, 2: box
        map<char, bool> sudoku[3][9];
        int len = 9;
        char ch;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                ch = board[i][j];
                if (ch == '.') continue;

                // row
                if (sudoku[0][i][ch]) return false;
                sudoku[0][i][ch] = true;

                // col
                if (sudoku[1][j][ch]) return false;
                sudoku[1][j][ch] = true;

                // box
                if (sudoku[2][3 * (i / 3) + j / 3][ch]) return false;
                sudoku[2][3 * (i / 3) + j / 3][ch] = true;
            }
        }

        return true;
    }
};

// Set, O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> r[9], c[9], b[9];
        char ch;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                ch = board[i][j];
                if (ch == '.') continue;

                int bidx = 3 * (i / 3) + (j / 3);
                if (r[i].count(ch) || c[j].count(ch) || b[bidx].count(ch)) return false;

                r[i].insert(ch);
                c[j].insert(ch);
                b[bidx].insert(ch);
            }
        }

        return true;
    }
};
