// Time: O(n), Space: O(1)
class Solution {
public:
    int dfs(TreeNode* root, int depth) {
        if (root == nullptr) return depth;
        return max(dfs(root->left, depth+1), dfs(root->right, depth+1));
    }
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
};

// Another version, better solution
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int mxLeft = maxDepth(root->left);
        int mxRight = maxDepth(root->right);
        return max(mxLeft, mxRight) + 1;
    }
};