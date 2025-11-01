// Time: O(n), Space: O(n)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        bitset<101> exist;
        vector<int> ans;

        for (auto& num: nums) {
            if (exist[num]) {
                ans.push_back(num);
            }
            exist[num] = 1;
        }

        return ans; 
    }
};
