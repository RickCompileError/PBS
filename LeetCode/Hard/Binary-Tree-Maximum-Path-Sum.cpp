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
    int mx;
    
    int maxPath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = maxPath(root -> left);
        int rightMax = maxPath(root -> right);

        mx = max(mx, leftMax + rightMax + root -> val);
        mx = max(mx, leftMax + root -> val);
        mx = max(mx, rightMax + root -> val);
        mx = max(mx, root -> val);

        return max(root -> val, max(leftMax + root -> val, rightMax + root -> val));
    }

    int maxPathSum(TreeNode* root) {
        mx = INT_MIN;
        maxPath(root);
        return mx;
    }
};

// Optimize
class Solution {
public:
    int maxPath(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }

        int leftMax = max(maxPath(root -> left, res), 0);
        int rightMax = max(maxPath(root -> right, res), 0);

	res = max(res, root -> val + leftMax, rightMax);

	return root -> val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
	int res = INT_MIN;
        maxPath(root, res);
        return res;
    }
};
