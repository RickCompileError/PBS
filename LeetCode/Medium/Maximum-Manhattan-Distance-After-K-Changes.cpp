// Time: O(n), Space: O(1)
class Solution {
private:
    int distance(string s, char hr, char vt, int k) {
        int mxLen = 0;
        int sz = s.size();
        int counter = 0;

        for (int i = 0; i < sz; i++) {
            if (s[i] != hr && s[i] != vt) {
                s[i] = k-- > 0 ? 1 : -1;
            } else {
                s[i] = 1;
            }
            counter += s[i];
            mxLen = max(mxLen, counter);
        }

        return mxLen;
    }

public:
    int maxDistance(string s, int k) {
        int ans = 0;

        ans = max(ans, distance(s, 'N', 'E', k));
        ans = max(ans, distance(s, 'N', 'W', k));
        ans = max(ans, distance(s, 'S', 'E', k));
        ans = max(ans, distance(s, 'S', 'W', k));

        return ans;
    }
};
