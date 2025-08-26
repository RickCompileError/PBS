// Time: O(n), Space: O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cons = 0;

        for (auto& n: arr) {
            cons = n & 1 ? cons + 1 : 0;
            if (cons == 3) {
                return true;
            }
        }

        return false;
    }
};
