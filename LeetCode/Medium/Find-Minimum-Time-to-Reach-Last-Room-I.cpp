// Time: O(mnlogn), Space: O(mn)
class Solution {
private:
    pair<int,int> dirs[4]{{-1,0}, {0,-1}, {0,1}, {1,0}};

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int COL = moveTime.size();
        int ROW = moveTime[0].size();
        int minTime = 0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();
            minTime = max(minTime, v[0]);
            if (v[1] == COL - 1 && v[2] == ROW - 1) {
                break;
            }

            for (auto& dir: dirs) {
                int nxtC = v[1] + dir.first;
                int nxtR = v[2] + dir.second;

                if (nxtC < 0 || nxtC == COL || nxtR < 0 || nxtR == ROW || moveTime[nxtC][nxtR] < 0) {
                    continue;
                }

                pq.push({max(v[0]+1, max(nxtC+nxtR, moveTime[nxtC][nxtR]+1)), nxtC, nxtR});
                moveTime[nxtC][nxtR] = -1;
            }
        }

        return minTime;
    }
};

