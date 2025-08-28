// Time: O(nlogn), Space: O(n)
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int sz = grid.size();

        // sorted bottom-left triangle
        for (int i = sz - 1; i >= 0; i--) {
            int r = i, c = 0;
            vector<int> tmp;
            
            while (r < sz && c < sz) {
                tmp.push_back(grid[r++][c++]);
            }

            sort(tmp.begin(), tmp.end(), [](auto& a, auto& b) { return a > b; });

            r = i, c = 0;
            while (r < sz && c < sz) {
                grid[r++][c++] = tmp[c];
            }
        }

        // sorted top-right triangle
        for (int i = 1; i < sz; i++) {
            int r = 0, c = i;
            vector<int> tmp;
            
            while (r < sz && c < sz) {
                tmp.push_back(grid[r++][c++]);
            }

            sort(tmp.begin(), tmp.end());

            r = 0, c = i;
            while (r < sz && c < sz) {
                grid[r++][c++] = tmp[r];
            }
        }

        return grid;
    }
};

// Use priority_queue, Time: O(mnlog(mn)), Space: O(mn)
