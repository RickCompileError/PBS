// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i: asteroids) {
            if (i > 0) ans.emplace_back(i);
            if (i < 0) {
                bool isDestroy = false;
                while (!ans.empty() && !isDestroy && ans.back() > 0) {
                    if (ans.back() >= abs(i)) isDestroy = true;
                    if (ans.back() <= abs(i)) ans.pop_back();
                }
                if (!isDestroy) ans.emplace_back(i);
            }
        }
        return ans;
    }
};