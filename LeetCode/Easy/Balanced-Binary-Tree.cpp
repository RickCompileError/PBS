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
    bool balanced;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lHeight = dfs(root -> left);
        int rHeight = dfs(root -> right);

        if (abs(lHeight - rHeight) > 1) {
            balanced = false;
        }

        return max(lHeight, rHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }
};
