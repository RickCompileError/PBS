// Time: O(n), Space: O(1)
// Recursive
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        if (root->val > val) return  searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return root;
    }
};
// Iterative
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root && root->val != val) {
            if (root->val > val) root = root->left;
            else root = root->right;
        }
        return root;
    }
};