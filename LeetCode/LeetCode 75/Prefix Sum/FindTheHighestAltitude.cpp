// Time: O(n), Space: O(1)
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cumulate = 0;
        for (int i: gain) {
            cumulate += i;
            ans = max(ans, cumulate);
        }
        return ans;
    }
};