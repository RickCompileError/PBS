// Time: O(n), Space: O(1)
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