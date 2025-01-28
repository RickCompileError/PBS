// Time: O(n*2^n), Space: O(n*2^n)
class Solution {
private:
    vector<int> key;
    map<int, int> amounts;
    vector<vector<int>> ans;
    
    void backtracking(vector<int> subs, int idx) {
        if (idx == key.size()) {
            ans.push_back(subs);
            return;
        }
        backtracking(subs, idx + 1);
        for (int i = 0; i < amounts[key[idx]]; i++) {
            subs.push_back(key[idx]);
            backtracking(subs, idx + 1);
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for (auto& i: nums) {
            if (!amounts[i]) {
                key.push_back(i);
            }
            amounts[i]++;
        }

        vector<int> subs;
        backtracking(subs, 0);
        return ans;
    }
};

// Time: (n*2^n), Space: O(n)
class Solution {
private:
    vector<vector<int>> ans;
    int sz;

    void backtracking(vector<int>& nums, vector<int>& subs, int idx) {
        ans.push_back(subs);
        for (int i = idx; i < sz; i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            subs.push_back(nums[i]);
            backtracking(nums, subs, i + 1);
            subs.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sz = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        backtracking(nums, res, 0);
        return ans;
    }
};

// Iterate version, Time: O(n*2^n), Space: O(1)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        sort(nums.begin(), nums.end());

        int sz = nums.size();
        for (int i = 0; i < sz;) {
            int count = 0;
            while (i + count < sz && nums[i] == nums[i + count]) count++;

            int prevSubsSize = subs.size();
            for (int j = 0; j < prevSubsSize; j++) {
                vector<int> s = subs[j];
                for (int k = 0; k < count; k++) {
                    s.push_back(nums[i]);
                    subs.push_back(s);
                }
            }

            i += count;
        }

        return subs;
    }
};
