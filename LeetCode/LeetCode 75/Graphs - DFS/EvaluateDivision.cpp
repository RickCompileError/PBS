// Time: O(E + Q * (V + E)), Space: O(n)
// E is building the graph, same as equations size
// Q is evaluating the queries, same as queries size
// (V + E) is dfs complexity
class Solution {
public:

    double executeQuery(unordered_map<string, unordered_map<string, double>>& tree, unordered_map<string, bool>& visited, string str1, string str2) {
        visited[str1] = true;
        double val;
        for (auto [k, v]: tree[str1]) {
            if (visited[k]) continue;
            if (k == str2) return v;
            val = executeQuery(tree, visited, k, str2);
            if (val > 0) return v * val;
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> tree;
        unordered_map<string, bool> exist;
        vector<double> ans;
        int sz = equations.size();
        string str1, str2;
        for (int i = 0; i < sz; i++) {
            str1 = equations[i][0];
            str2 = equations[i][1];
            exist[str1] = exist[str2] = true;
            tree[str1][str2] = values[i];
            tree[str2][str1] = 1/values[i];
        }
        for (vector<string> query: queries) {
            str1 = query[0];
            str2 = query[1];
            if (!exist[str1] || !exist[str2]) {
                ans.push_back(-1);
                continue;
            }
            if (str1 == str2) {
                ans.push_back(1);
                continue;
            }
            unordered_map<string, bool> visited;
            ans.push_back(executeQuery(tree, visited, str1, str2));
        }
        return ans;
    }
};