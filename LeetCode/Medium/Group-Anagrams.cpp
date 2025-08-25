// map and sort, O(mlogn)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, int> exist;
        int idx = 1, sz = strs.size();

        for (int i = 0; i < sz; i++) {
            string org = strs[i];
            sort(strs[i].begin(), strs[i].end());

            if (!exist[strs[i]]) {
                exist[strs[i]] = idx++;
                ans.push_back({});
            }

            ans[exist[strs[i]] - 1].push_back(org);
        }

        return ans;
    }
};

// clear version
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> find;

        for (string& s: strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            find[tmp].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& m: find) {
            ans.push_back(m.second);
        }

        return ans;
    }
};

// O(m*n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> u;

        for (string& s: strs) {
            array<int, 26> count = {0};

            for (char c: s) count[c - 97]++;

            string hash = "";
            for (int num: count) hash += to_string(num) + "#";

            u[hash].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto& a: u) ans.push_back(a.second);

        return ans;
    }
};
