// Time: O(n), Space: O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int sz = startTime.size();
        vector<int> gap(sz + 1, 0);
        vector<int> rightMaxGap(sz + 1, 0);

        gap[0] = startTime[0];
        for (int i = 1; i < sz; i++) {
            gap[i] = startTime[i] - endTime[i - 1];
        }
        gap[sz] = eventTime - endTime[sz - 1];

        for (int i = sz - 1; i >= 0; i--) {
            rightMaxGap[i] = max(rightMaxGap[i + 1], gap[i + 1]);
        }

        int mxFree = 0, leftMaxGap = 0;
        for (int i = 1; i <= sz; i++) {
            int duration = endTime[i - 1] - startTime[i - 1];
            bool canMoveLeft = leftMaxGap >= duration;
            bool canMoveRight = rightMaxGap[i] >= duration;

            if (canMoveLeft || canMoveRight) {
                mxFree = max(mxFree, gap[i - 1] + gap[i] + duration);
            }

            mxFree = max(mxFree, gap[i - 1] + gap[i]);
            leftMaxGap = max(leftMaxGap, gap[i - 1]);
        }

        return mxFree;
    }
};
