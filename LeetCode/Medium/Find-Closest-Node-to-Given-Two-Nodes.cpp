// Time: O(n), Space: O(n)
class Solution {
private:
    void dfs(vector<int>& edges, int node, int len, vector<int>& dst) {
        dst[node] = len;
        if (edges[node] != -1 && dst[edges[node]] == -1) {
            dfs(edges, edges[node], len + 1, dst);
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int sz = edges.size();
        vector<int> dst1(sz, -1), dst2(sz, -1);
        dfs(edges, node1, 0, dst1);
        dfs(edges, node2, 0, dst2);

        for (auto& i: dst1) cout << i <<' ';
        cout <<endl;
        for (auto& i: dst2) cout << i <<' ';

        int mnIdx = -1, mnDst = INT_MAX;
        for (int i = 0; i < sz; i++) {
            if (dst1[i] == -1 || dst2[i] == -1) {
                continue;
            }
            int dst = max(dst1[i], dst2[i]);
            if (dst == mnDst) {
                mnIdx = min(mnIdx, i);
            } else if (dst < mnDst) {
                mnDst = dst;
                mnIdx = i;
            }
        }

        return mnDst == INT_MAX ? -1 : mnIdx;
    }
};
