// Time: O(n), Space: O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int comb = 0;
        unordered_map<string,int> um;

        for (auto& dominoe: dominoes) {
            if (dominoe[0] > dominoe[1]) {
                swap(dominoe[0], dominoe[1]);
            }
            string to_str = to_string(dominoe[0]) + to_string(dominoe[1]);
            um[to_str]++;
        }

        for (auto& [k,v]: um) {
            comb += v * (v - 1) / 2;
        }

        return comb;
    }
};
