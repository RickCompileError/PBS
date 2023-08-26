// Time: O(height of tree), Space: O(1)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val > key) root->left = deleteNode(root->left, key);
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) return NULL;
            if (!root->left || !root->right) return root->left ? root->left : root->right;
            TreeNode* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            root->val = tmp->val;
            root->left = deleteNode(root->left, tmp->val);
        }
        return root;
    }
};