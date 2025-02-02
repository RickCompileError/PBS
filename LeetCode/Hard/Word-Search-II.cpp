// Backtracking, Time: O(p*q*2^(q)), Space: O(q), p is the amounts of words, q is the board size, Time Limit Exceeded
class Solution {
private:
    int m;
    int n;

    bool check(string str, vector<vector<char>>& board) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if (board[i][j] == str[0] && backtracking(str, 0, i, j, board, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtracking(string str, int idx, int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (idx == str.size()) {
            return true;
        }

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != str[idx] || visited[r][c]) {
            return false;
        }

        visited[r][c] = true;
        if (backtracking(str, idx + 1, r - 1, c, board, visited) ||
            backtracking(str, idx + 1, r + 1, c, board, visited) ||
            backtracking(str, idx + 1, r, c - 1, board, visited) ||
            backtracking(str, idx + 1, r, c + 1, board, visited)) {
            return true;
        }
        visited[r][c] = false;

        return false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        vector<string> res;
        for (auto& i: words) {
            if (check(i, board)) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// Trie + DFS, Time: O(M*N + (P*Q)^2), Space: O(M*N)
// M is the average length of word
// N is the amount of words
// P, Q represent P x Q board
// M*N is the time and space complexity to build the Trie
// P*Q is the time complexity for the DFS for each cell
class Trie {
public:
    int idx;
    unordered_map<char, Trie*> childs;

    Trie() {
        idx = -1;
    }

    void addWord(string& word, int idx) {
        Trie* node = this;
        for (auto& c: word) {
            if (node -> childs[c] == nullptr) {
                node -> childs[c] = new Trie();
            }
            node = node -> childs[c];
        }
        node -> idx = idx;
    }
};

class Solution {
private:
    int ROWS;
    int COLS;
    vector<string> res;
    Trie* root;

    void dfs(vector<vector<char>>& board, int r, int c, Trie* node, vector<string>& words) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            board[r][c] == '#' || node -> childs[board[r][c]] == nullptr) {
            return;
        }


        char ch = board[r][c];
        node = node -> childs[ch];
        board[r][c] = '#';
        if (node -> idx != -1) {
            res.push_back(words[node -> idx]);
            node -> idx = -1;
        }

        dfs(board, r + 1, c, node, words);
        dfs(board, r - 1, c, node, words);
        dfs(board, r, c + 1, node, words);
        dfs(board, r, c - 1, node, words);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        ROWS = board.size();
        COLS = board[0].size();
        root = new Trie();
        res.clear();

        for (int i = 0; i < words.size(); i++) {
            root -> addWord(words[i], i);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                dfs(board, i, j, root, words);
            }
        }

        return res;
    }
};
