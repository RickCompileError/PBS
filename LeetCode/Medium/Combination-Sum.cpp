// Time: O(2^(t/m)), Space: O(t/m), t is target, m is the minimum value in candidates
class Solution {
private:
    vector<vector<int>> combination;

public:
    void backtracking(vector<int>& candidates, vector<int>& comb, int idx, int target) {
        if (idx == candidates.size()) {
            return;
        }
        
        comb.push_back(candidates[idx]);
        if (candidates[idx] == target) {
            combination.push_back(comb);
        } else if (candidates[idx] < target) {
            backtracking(candidates, comb, idx, target - candidates[idx]);
        }

        comb.pop_back();
        if (target > 0) {
            backtracking(candidates, comb, idx + 1, target);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        backtracking(candidates, comb, 0, target);
        return combination;
    }
};

// To optimize the above code, we can sort the candidates first,
// and do the early return if the candidates + total > target
