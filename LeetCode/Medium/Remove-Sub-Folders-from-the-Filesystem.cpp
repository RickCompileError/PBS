// Time: O(nk), Space: O(n), k is avg string size
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        int sz = folder.size();
        vector<string> ans;

        ans.push_back(folder.front());
        for (int i = 1; i < sz; i++) {
            string root = ans.back() + "/";

            if (folder[i].compare(0, root.size(), root) != 0) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
