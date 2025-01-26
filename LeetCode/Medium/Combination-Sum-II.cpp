// Time: O(2^n), Space: O(n)
class Solution {
    vector<vector<int>> combination;
    unordered_map<int,int> candAmount;
    vector<int> key;

public:
    void backtracking(vector<int>& comb, int idx, int target) {
        if (target == 0) {
            combination.push_back(comb);
            return;
        }

        if (target < 0 || idx == key.size()) {
            return;
        }

        if (candAmount[key[idx]]) {
            comb.push_back(key[idx]);
            candAmount[key[idx]]--;
            backtracking(comb, idx, target - key[idx]);
            candAmount[key[idx]]++;
            comb.pop_back();
        }

        backtracking(comb, idx + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto& i: candidates) {
            if (candAmount[i] == 0) {
                key.push_back(i);
            }
            candAmount[i]++;
        }
        vector<int> comb;
        backtracking(comb, 0, target);
        return combination;
    }
};

// Optimized
class Solution {
    vector<vector<int>> combination;

public:
    void backtracking(vector<int>& candidates, vector<int>& comb, int idx, int target) {
        if (target == 0) {
            combination.push_back(comb);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);
            backtracking(candidates, comb, i + 1, target - candidates[i]);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        backtracking(candidates, comb, 0, target);
        return combination;
    }
};
