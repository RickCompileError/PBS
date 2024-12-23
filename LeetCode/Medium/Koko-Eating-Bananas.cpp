// O(nlogn)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0, mid;
        for (int i: piles) right = max(right, i);
        while (left <= right) {
            mid = left + (right - left) / 2;
            long long times = 0;
            for (int i: piles) times += (i + mid - 1) / mid;
            if (times <= h) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};
