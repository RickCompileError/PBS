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
    int isGood(TreeNode* node, int mxVal) {
        if (node == nullptr) return 0;
        return (node->val >= mxVal) + isGood(node->left, max(mxVal, node->val)) + isGood(node->right, max(mxVal, node->val));
    }
    int goodNodes(TreeNode* root) {
        return isGood(root, root->val);
    }
};
