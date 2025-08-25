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
    int findKth(TreeNode* root, int& k) {
        if (root == nullptr) {
            return -1;
        }
        int ans = 0;
        ans = findKth(root -> left, k);
        if (k == 0) {
            return ans;
        }
        k--;
        if (k == 0) {
            return root -> val;
        }
        ans = findKth(root -> right, k);
        if (k == 0) {
            return ans;
        }
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        return findKth(root, k);
    }
};

// Optimized
class Solution {
public:
    void findKth(TreeNode* root, int k, int& counter, int& ans) {
        if (root == nullptr || counter >= k) {
            return;
        }

        findKth(root -> left, k, counter, ans);
        if (++counter == k) {
            ans = root -> val;
        }
        findKth(root -> right, k, counter, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int ans = -1;
        findKth(root, k, counter, ans);
        return ans;
    }
};
