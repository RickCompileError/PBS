// Time: O(n), Space: O(n)
// Iterative solution
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        int lv = 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root, lv});
        while (!q.empty()) {
            auto [node, level] = q.front(); q.pop();
            if (lv == level) {
                ans.push_back(node->val);
                lv++;
            }
            if (node->right) q.push({node->right, lv});
            if (node->left) q.push({node->left, lv});
        }
        return ans;
    }
};

// Recursive solution
class Solution {
public:
    void bfs(TreeNode* node, int level, vector<int> &ans) {
        if (node == nullptr) return;
        if (ans.size() < level) ans.push_back(node->val);
        bfs(node->right, level + 1, ans);
        bfs(node->left, level + 1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        bfs(root, 1, ans);
        return ans;
    }
};