// Time: O(n), Memory: O(n)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        map<int, int> m;
        for (int i: nums) m[i]++;
        for (auto i: m) {
            if (i.first > k / 2) break;
            if (i.first == k - i.first) ans += i.second / 2;
            else ans += min(i.second, m[k - i.first]);
        }
        return ans;
    }
};

// Unordered map version
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i: nums) m[i]++;
        for (auto i: m) {
            if (i.first == k - i.first) ans += i.second / 2;
            else if (m.find(k - i.first) != m.end()) {
                ans += min(i.second, m[k - i.first]);
                m[i.first] = m[k - i.first] = 0;
            }
        }
        return ans;
    }
};

// Another version is using two pointer, the array need sort first, so the time complexity is O(nlogn)
// But suprisingly, the runtime result is better than map and unordered map
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0, i = 0, j = nums.size() - 1, tot;
        sort(nums.begin(), nums.end());
        while (i < j) {
            tot = nums[i] + nums[j];
            if (tot == k) i++, j--, ans++;
            else if (tot < k) i++;
            else j--;
        }
        return ans;
    }
};