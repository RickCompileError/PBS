// Time: O(n), Space: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, accumulate = 0;
        for (int i: gain) {
            accumulate += i;
            ans = max(ans, accumulate);
        }
        return ans;
    }
};