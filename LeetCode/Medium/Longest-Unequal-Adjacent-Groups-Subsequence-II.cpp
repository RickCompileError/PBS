// Time: O(n^2), Space: O(n)
class Solution {
private:
    bool isOneHamming(string& a, string& b) {
        int sz = a.size();
        if (sz != b.size()) {
            return false;
        }

        bool diff = false;
        for (int i = 0; i < sz; i++) {
            if (a[i] != b[i]) {
                if (diff) {
                    return false;
                }
                diff = true;
            }
        }
        return diff;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int sz = words.size();
        map<int,vector<int>> lengthIdx;
        vector<string> ans;

        for (int i = 0; i < sz; i++) {
            lengthIdx[words[i].size()].push_back(i);
        }

        for (auto& [len, idxList]: lengthIdx) {
            int idxSz = idxList.size();
            int mxStart = idxSz - 1;
            vector<pair<int,int>> dp(idxList.size());
            for (int i = 0; i < idxSz; i++) {
                dp[i] = {1, i};
            }
            for (int i = idxSz - 1; i >= 0; i--) {
                for (int j = i + 1; j < idxSz; j++) {
                    if (groups[idxList[i]] == groups[idxList[j]]) {
                        continue;
                    }
                    if (isOneHamming(words[idxList[i]], words[idxList[j]])) {
                        if (dp[i].first < dp[j].first + 1) {
                            dp[i] = {dp[j].first + 1, j};
                        }
                    }
                }
                if (dp[i].first > dp[mxStart].first) {
                    mxStart = i;
                }
            }
            if (dp[mxStart].first > ans.size()) {
                vector<string> tmp;
                while (mxStart != dp[mxStart].second) {
                    tmp.push_back(words[idxList[mxStart]]);
                    mxStart = dp[mxStart].second;
                }
                tmp.push_back(words[idxList[mxStart]]);
                ans = tmp;
            }
        }

        return ans;
    }
};

// More precise, Time: O(n^2), Space: O(n)
class Solution {
private:
    bool isHamming1(string& a, string& b) {
        int sz = a.size();
        if (sz != b.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < sz; i++) {
            diff += a[i] != b[i];
        }
        return diff == 1;
    }

public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int sz = words.size();
        int mxLen = 0, pos = -1;
        vector<int> dp(sz,1), prev(sz, -1);
        vector<string> ans;

        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j] || !isHamming1(words[i], words[j])) {
                    continue;
                }
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > mxLen) {
                mxLen = dp[i];
                pos = i;
            }
        }

        for (; pos != -1; pos = prev[pos]) {
            ans.push_back(words[pos]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
