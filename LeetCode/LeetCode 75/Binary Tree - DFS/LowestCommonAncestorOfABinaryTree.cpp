// Time: O(n^2), Space: O(depth of tree)
class Solution {
public:

    bool find(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return false;
        if (root->val == p->val) return true;
        return find(root->left, p) || find(root->right, p);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) return root;
        bool pInLeft = find(root->left, p), qInLeft = find(root->left, q);
        if (pInLeft && qInLeft) return lowestCommonAncestor(root->left, p, q);
        else if (pInLeft || qInLeft) return root;
        else return lowestCommonAncestor(root->right, p, q);
    }
};

// Time: O(n), Space: O(n)
// Faster approach, the classic code to execute a lowest common ancestor
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
};