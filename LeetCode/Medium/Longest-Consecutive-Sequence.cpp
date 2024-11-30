// O(n), pq
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        priority_queue<int, vector<int>, greater<>> pq;
        for (auto& i: nums) pq.push(i);

        int cur = pq.top(), con = 1, ans = 0;
        pq.pop();
        while (!pq.empty()) {
            if (cur == pq.top()) {
                pq.pop();
                continue;
            }
            
            if (cur + 1 == pq.top()) {
                cur = pq.top();
                con++;
            } else {
                ans = max(ans, con);
                cur = pq.top();
                con = 1;
            }
            pq.pop();
        }

        return max(ans, con);
    }
};

// O(n), set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0, length = 0;

        for (auto& i: us) {
            if (us.find(i - 1) == us.end()) {
                length = 1;
                while (us.find(i + length) != us.end()) length++;
                ans = max(length, ans);
            }
        }

        return ans;
    }
};
