// Time: O(n), Space: O(depth of tree)
class Solution {
public:

    int dfs(TreeNode* root, bool isLeft, int len) {
        if (root == nullptr) return len;
        if (isLeft) return max(dfs(root->left, true, 1), dfs(root->right, false, len + 1));
        else return max(dfs(root->left, true, len + 1), dfs(root->right, false, 1));
    }
    
    int longestZigZag(TreeNode* root) {
        return max(dfs(root->left, true, 1), dfs(root->right, false, 1)) - 1;
    }
};