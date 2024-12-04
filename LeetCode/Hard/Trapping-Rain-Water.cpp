// O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size(), ans = 0;

        int idx = 0;
        vector<int> leftTopPoint{idx};

        while (++idx < sz) {
            if (height[leftTopPoint.back()] <= height[idx]) {
                leftTopPoint.push_back(idx);
            }
        }

        for (int i = 1; i < leftTopPoint.size(); i++) {
            int minH = min(height[leftTopPoint[i - 1]], height[leftTopPoint[i]]);
            for (int j = leftTopPoint[i - 1] + 1; j < leftTopPoint[i]; j++) {
                ans += minH - height[j];
            }
        }

        idx = sz - 1;
        vector<int> rightTopPoint{idx};

        while (--idx >= leftTopPoint.back()) {
            if (height[rightTopPoint.back()] <= height[idx]) {
                rightTopPoint.push_back(idx);
            }
        }

        for (int i = 1; i < rightTopPoint.size(); i++) {
            int minH = min(height[rightTopPoint[i - 1]], height[rightTopPoint[i]]);
            for (int j = rightTopPoint[i - 1] - 1; j > rightTopPoint[i]; j--) {
                ans += minH - height[j];
            }
        }

        return ans;
    }
};

// O(n), clear
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int l = 0;
        int r = sz - 1;
        int ml = height[l];
        int mr = height[r];
        int ans = 0;

        while (l < r) {
            if (ml < mr) {
                l++;
                ml = max(ml, height[l]);
                ans += ml - height[l];
            } else {
                r--;
                mr = max(mr, height[r]);
                ans += mr - height[r];
            }
        }

        return ans;
    }
};
