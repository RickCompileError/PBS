// Time: O(n), Space: O(n)
class Solution {
public:
    int maxDifference(string s, int k) {
        int sz = s.size();
        int ans = INT_MIN;

        // Total only 20 pairs
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                if (a == b) {
                    continue;
                }

                vector<int> p1(sz + 1);
                vector<int> p2(sz + 1);

                // Prefix Sum
                for (int i = 1; i <= sz; i++) {
                    p1[i] = p1[i - 1] + (s[i - 1] - '0' == a);
                    p2[i] = p2[i - 1] + (s[i - 1] - '0' == b);
                }

                // Save the diff of a and b
                // Index base on the parity of a and b
                int parity[2][2] = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
                int j = 0;

                // Sliding Window
                for (int i = k; i <= sz; i++) {
                    // Stop when len smaller than k or the substr has no a or b
                    while (i - j >= k && p1[i] > p1[j] && p2[i] > p2[j]) {
                        int pa = p1[j] & 1;
                        int pb = p2[j] & 1;
                        parity[pa][pb] = max(parity[pa][pb], p2[j] - p1[j]);
                        j++;
                    }

                    int pa = p1[i] & 1;
                    int pb = p2[i] & 1;
                    int p = parity[1 - pa][pb];

                    if (p != INT_MIN) {
                        ans = max(ans, (p1[i] - p2[i]) + p);
                    }
                }
            }
        }

        return ans == INT_MIN ? -1 : ans;
    }
};
