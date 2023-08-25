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
    int maxLevelSum(TreeNode* root) {
        int level = 0, sz, sum, mxSum = INT_MIN, ans = 0;
        TreeNode* tmp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            sz = q.size();
            sum = 0;
            while (sz--) {
                tmp = q.front();
                q.pop();
                sum += tmp->val;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            if (sum > mxSum) {
                mxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
};