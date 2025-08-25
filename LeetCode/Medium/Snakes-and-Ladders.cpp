// Time: O(n^2), Space: O(n^2)
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int sz = board.size();
        int bsz = sz * sz;
        bool fromLeft = true;
        vector<int> flatten(1, -1);

        for (int i = sz - 1; i >= 0; i--) {
            if (fromLeft) {
                for (int j = 0; j < sz; j++) {
                    flatten.push_back(board[i][j]);
                }
            } else {
                for (int j = sz - 1; j >= 0; j--) {
                    flatten.push_back(board[i][j]);
                }
            }
            fromLeft = !fromLeft;
        }

        vector<int> steps(bsz + 1, -1);
        queue<int> q;

        steps[1] = 0;
        q.push(1);
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int i = cur + 1; i <= min(cur + 6, bsz); i++) {
                int nxt = flatten[i] > 0 ? flatten[i] : i;
                if (nxt == bsz) {
                    return steps[cur] + 1;
                }
                if (steps[nxt] == -1) {
                    steps[nxt] = steps[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        return -1;
    }
};
