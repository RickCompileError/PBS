// Time: O(mnlogn), Space: O(mn)
class Solution {
private:
    pair<int,int> DIRS[4]{{1,0},{0,1},{-1,0},{0,-1}};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int ROWS = moveTime.size();
        int COLS = moveTime[0].size();
        int minTime = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0,0});

        while (!pq.empty()) {
            vector<int> curState = pq.top();
            pq.pop();

            if (curState[1] + 1 == ROWS && curState[2] + 1 == COLS) {
                return curState[0];
            }

            for (auto& dir: DIRS) {
                int nxtRow = curState[1] + dir.first;
                int nxtCol = curState[2] + dir.second;
                // the time to take for the next move
                int nxtTime = curState[3] ? 2 : 1;

                if (nxtRow < 0 || nxtRow == ROWS || nxtCol < 0 || nxtCol == COLS || moveTime[nxtRow][nxtCol] < 0) {
                    continue;
                }

                pq.push({
                    max(curState[0], moveTime[nxtRow][nxtCol]) + nxtTime,
                    nxtRow,
                    nxtCol,
                    curState[3] ^ 1
                });
                moveTime[nxtRow][nxtCol] = -1;
            }

        }

        return -1;
    }
};
