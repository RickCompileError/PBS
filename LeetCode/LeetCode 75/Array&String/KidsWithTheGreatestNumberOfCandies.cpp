// Complexity: O(n), Space: O(n)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), false);
        int mx = *max_element(candies.begin(), candies.end());
        for (int i = 0; i < candies.size(); i++) ans[i] = (candies[i] + extraCandies >= mx);
        return ans;
    }
};

// Another solution, remove initialize
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mx = *max_element(candies.begin(), candies.end());
        for (int i: candies) ans.emplace_back((candies[i] + extraCandies >= mx ? true : false));
        return ans;
    }
};