// Time: O(nlogn), Space: O(n)
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int sz = nums.size();
        int qsz = queries.size();
        int operation = 0;
        priority_queue<int> pq;
        vector<int> deltaArr(sz + 1, 0);

        sort(queries.begin(), queries.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        for (int i = 0, j = 0; i < sz; i++) {
            operation += deltaArr[i];

            while (j < qsz && queries[j][0] == i) {
                pq.push(queries[j][1]);
                j++;
            }

            while (operation < nums[i] && !pq.empty() && pq.top() >= i) {
                operation++;
                deltaArr[pq.top() + 1]--;
                pq.pop();
            }

            if (operation < nums[i]) {
                return -1;
            }
        }

        return pq.size();
    }
};
