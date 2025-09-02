// Time: O(nlogn + n^2), Space: O(1)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });


        int ans = 0;
        int sz = points.size();

        for (int i = 0; i < sz; i++) {
            int mxHeight = -1;
            for (int j = i + 1; j < sz; j++) {
                if (points[j][1] > points[i][1]) {
                    continue;
                }

                ans += (mxHeight < points[j][1]);
                mxHeight = max(mxHeight, points[j][1]);
            }
        }

        return ans;
    }
};
