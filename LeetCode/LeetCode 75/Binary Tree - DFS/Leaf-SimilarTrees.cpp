// Time: O(n), Space: O(m+n)
class Solution {
public:
    void getLeaf(vector<int> &v, TreeNode* node) {
        if (node->left) getLeaf(v, node->left);
        if (node->right) getLeaf(v, node->right);
        if (node->left == nullptr && node->right == nullptr) v.emplace_back(node->val);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaf(leaf1, root1);
        getLeaf(leaf2, root2);
        return leaf1 == leaf2;
    }
};