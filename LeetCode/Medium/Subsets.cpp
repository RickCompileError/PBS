// Backtracking, O(n * 2^n), Space(n)
class Solution {
private:
    vector<vector<int>> sets;

public:
    void backtracking(vector<int>& nums, int idx, vector<int>& v) {
        if (idx == nums.size()) {
            sets.push_back(v);
            return;
        }
        v.push_back(nums[idx]);
        backtracking(nums, idx + 1, v);
	v.pop_back();
        backtracking(nums, idx + 1, v);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> base{};
        sets.clear();
        backtracking(nums, 0, base);
        return sets;
    }
};

// Bit manipulation
class Solution {
private:
    vector<vector<int>> sets;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sets.clear();
        int sz = nums.size();
        for (int i = 0; i < (1 << sz); i++) {
            vector<int> s;
            for (int j = 0; j < sz; j++) {
                if (i & (1 << j)) {
                    s.push_back(nums[j]);
                }
            }
            sets.push_back(s);
        }
        return sets;
    }
};
