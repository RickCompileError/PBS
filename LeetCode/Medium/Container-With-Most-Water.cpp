class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, l = 0, r = height.size() - 1, area;

        while (l < r) {
            area = min(height[l], height[r]) * (r - l);

            ans = max(ans, area);

            height[l] < height[r] ? l++ : r--;
        }

        return ans;
    }
};
