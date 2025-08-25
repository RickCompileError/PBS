// Time: O(n), Space: O(1)
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        int ans = word.size();

        for (auto& c: word) {
            freq[c - 'a']++;
        }
        for (auto& f: freq) {
            if (f == 0) {
                continue;
            }
            int del = 0;
            // Fix the min to f, so every n < f will be deleted
            for (auto& n: freq) {
                del += (n < f) ? n : max(0, n - (f + k));
            }
            ans = min(ans, del);
        }

        return ans;
    }
};
