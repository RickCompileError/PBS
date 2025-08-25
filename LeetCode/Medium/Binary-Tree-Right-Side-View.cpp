/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
