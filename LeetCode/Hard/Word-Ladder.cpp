// DFS, Time: O(n!), Space: O(n^2)
class Solution {
private:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adjacent;
    int ans = INT_MAX;

    void buildAdjacent(vector<string>& wordList) {
        int sz = wordList.size();
        int ssz = wordList[0].size();

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int diff = 0;
                for (int k = 0; k < ssz; k++) {
                    diff += (wordList[i][k] != wordList[j][k]);
                }
                if (diff == 1) {
                    adjacent[wordList[i]].push_back(wordList[j]);
                    adjacent[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    void dfs(string currentWord, string& endWord) {
        if (currentWord == endWord) {
            ans = min(ans, (int)visited.size());
            return;
        }

        for (auto& nxt: adjacent[currentWord]) {
            if (visited.find(nxt) != visited.end()) {
                continue;
            }

            visited.insert(nxt);
            dfs(nxt, endWord);
            visited.erase(nxt);
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        buildAdjacent(wordList);
        visited.insert(beginWord);
        dfs(beginWord, endWord);
        return ans == INT_MAX ? 0 : ans;
    }
};

// BFS, because the answer the shortest seq, BFS is better than DFS
// Time: O(n^2), Space: O(n^2)
class Solution {
private:
    unordered_map<string, vector<string>> adjacent;

    void buildAdjacent(vector<string>& wordList) {
        int sz = wordList.size();
        int ssz = wordList[0].size();

        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                int diff = 0;
                for (int k = 0; k < ssz; k++) {
                    diff += (wordList[i][k] != wordList[j][k]);
                }
                if (diff == 1) {
                    adjacent[wordList[i]].push_back(wordList[j]);
                    adjacent[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited(wordList.begin(), wordList.end());
        wordList.push_back(beginWord);
        buildAdjacent(wordList);

        int res = 0;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            res++;
            int len = q.size();
            while (len--) {
                string cur = q.front();
                q.pop();

                if (cur == endWord) {
                    return res;
                }

                for (auto& nxt: adjacent[cur]) {
                    if (visited.find(nxt) == visited.end()) {
                        continue;
                    }
                    q.push(nxt);
                    visited.erase(nxt);
                }
            }
        }

        return 0;
    }
};

// Another optimized is not build the adjacent table, do the compare at every bfs
// Because the string only compose of lowercase so it can have a little bit faster in the extreme case
// Time: O(m^2*n), Space: O(m^2*n), m is length of string, n is size of array

// Another way is "Meet in the Middle", it still the BFS but maintain two queues
// Run the BFS from begin and end simultaneously
