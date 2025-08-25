// Time: O(nlogn), Space: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int sz = points.size();
        int arrows = 1;
        int end;

        sort(points.begin(), points.end(), [](auto& a, auto& b) { return a.back() < b.back();});
        end = points[0].back();
        for (auto& point: points) {
            if (point.front() <= end) {
                continue;
            }
            end = point.back();
            arrows++;
        }

        return arrows;
    }
};
