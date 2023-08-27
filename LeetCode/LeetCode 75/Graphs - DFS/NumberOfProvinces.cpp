// Time: O(n ^ 2), Space: O(n)
class Solution {
public:
    int sz;

    void makeConnection(vector<vector<int>>& isConnected, vector<bool>& connect, int city) {
        if (connect[city]) return;
        connect[city] = true;
        for (int i = 0; i < sz; i++)
            if (isConnected[city][i] && !connect[i]) makeConnection(isConnected, connect, i);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        sz = isConnected.size();
        vector<bool> connect(sz, false);
        int province = 0;
        for (int i = 0; i < sz; i++) {
            if (!connect[i]) {
                makeConnection(isConnected, connect, i);
                province++;
            }
        }
        return province;
    }
};