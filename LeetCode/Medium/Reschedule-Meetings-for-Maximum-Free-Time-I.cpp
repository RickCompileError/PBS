// Time: O(n), Space: O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> timeGap;
        int sz = startTime.size();
        int mxFreeTime = 0;
        int slidingFreeTime = 0;

        timeGap.push_back(startTime[0]);
        for (int i = 1; i < sz; i++) {
            timeGap.push_back(startTime[i] - endTime[i - 1]);
        }
        timeGap.push_back(eventTime - endTime[sz - 1]);

        for (int i = 0; i <= k; i++) {
            slidingFreeTime += timeGap[i];
        }
        mxFreeTime = slidingFreeTime;
        for (int i = k + 1; i <= sz; i++) {
            slidingFreeTime += timeGap[i] - timeGap[i - k - 1];
            mxFreeTime = max(mxFreeTime, slidingFreeTime);
        }

        return mxFreeTime;
    }
};
