// Complexity: O(n), Space: O(1) 
// 這個技巧是根據我們只需要找隨機三個滿足條件的組合，就算 a, b 被更新了，因為在那之前 a, b 已經滿足條件，因此不會造成整體程式的運作
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int i: nums) {
            if (i <= a) a = i;
            else if (i <= b) b = i;
            else return true;
        }
        return false;
    }
};