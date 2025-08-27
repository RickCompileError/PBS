// O(s+t), t for build map, s for sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        unordered_map<char, int> um;
        for (auto& i: t) um[i]++;

        int sLen = s.length();
        int tRemaining = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIdx = 0;

        for (int endIdx = 0; endIdx < sLen; endIdx++) {
            char ch = s[endIdx];
            if (um.find(ch) != um.end() && um[ch] > 0) {
                tRemaining--;
            }
            um[ch]--;

            if (tRemaining == 0) {
                while (true) {
                    char charAtStart = s[startIdx];
                    if (um.find(charAtStart) != um.end() && um[charAtStart] == 0) {
                        break;
                    }
                    um[charAtStart]++;
                    startIdx++;
                }

                if (endIdx - startIdx < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIdx;
                    minWindow[1] = endIdx;
                }

                um[s[startIdx]]++;
                tRemaining++;
                startIdx++;
            }
        }

        return minWindow[1] >= sLen ? "" : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};
