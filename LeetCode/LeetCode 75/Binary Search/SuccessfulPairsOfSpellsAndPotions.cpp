// Time: O(nlogm + mlogm), Space: O(n)
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> pairs(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for (int i = 0, sz = spells.size(); i < sz; i++) {
            int left = 0, right = potions.size() - 1, mid;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if ((long long)spells[i] * potions[mid] < success) left = mid + 1;
                else right = mid - 1;
            }
            pairs[i] = potions.size() - left;
        }
        return pairs;
    }
};

// Time: O(mlogm + n*logm), Space: O(n)
// lower_bound version, the concept is also binary_search
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        for (int spell: spells) {
            long long least = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), least);
            pairs.push_back(potions.end() - it);
        }
        return pairs;
    }
};

// Another version is using HashMap