// Time: O(n!), Space: O(n!*n)
// If count on the possibility result push the answer vector, the time complexity is O(n!*n)
class Solution {
private:
    int sz;
    vector<vector<int>> ans;

    void permutation(vector<int>& nums, vector<int>& visited, vector<int>& res) {
        if (res.size() == sz) {
            ans.push_back(res);
            return;
        }
        
        for (int i = 0; i < sz; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            res.push_back(nums[i]);
            permutation(nums, visited, res);
            res.pop_back();
            visited[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        vector<int> visited(sz, 0);
        vector<int> res;
        permutation(nums, visited, res);
        return ans;
    }
};

// It can use bit mask to optimize

// Optimized version
class Solution {
private:
    int sz;
    vector<vector<int>> ans;

    void permutation(vector<int>& nums, int idx) {
        if (idx == sz) {
            ans.push_back(nums);
            return;
        }
        
        for (int i = idx; i < sz; i++) {
            swap(nums[idx], nums[i]);
            permutation(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        permutation(nums, 0);
        return ans;
    }
};
