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
// O(N^2)
class Solution {
public:
    int find(vector<int>& inorder, int val, int left, int right) {
        int i = left;
        for (; i <= right; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        return i;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& idx, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[idx]);
        int inIdx = find(inorder, preorder[idx++], left, right);

        root -> left = build(preorder, inorder, idx, left, inIdx - 1);
        root -> right = build(preorder, inorder, idx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        TreeNode* root = build(preorder, inorder, idx, 0, preorder.size() - 1);
        return root;
    }
};

// O(n)
class Solution {
private:
    int idx;
    unordered_map<int,int> um;
public:
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        root -> left = build(preorder, left, um[val] - 1);
        root -> right = build(preorder, um[val] + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        um.clear();
        for (int i = 0; i < inorder.size(); i++) {
            um[inorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1);
    }
};
