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
    int ans;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int lLen = dfs(root -> left);
        int rLen = dfs(root -> right);
        ans = max(ans, lLen + rLen);
        
        return max(lLen, rLen) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
