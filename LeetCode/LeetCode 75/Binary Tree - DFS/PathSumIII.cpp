// Time: O(n^2), Space: O(n)
#define ll long long
class Solution {
public:
    void dfs(TreeNode* root, vector<int> v, int &ans, int target) {
        if (root == nullptr) return;
        v.push_back(root->val);
        dfs(root->left, v, ans, target);
        dfs(root->right, v, ans, target);
        ll sum = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            sum += v[i];
            if (sum == target) ans++;
        }
        v.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        vector<int> v;
        dfs(root, v, ans, targetSum);
        return ans;
    }
};

// Time: O(n), Space: O(depth of tree)
// Not using vector, only recursive
#define ll long long
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, ll targetSum) {
        if (root == nullptr) return;
        if (root->val == targetSum) ans++;
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            dfs(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};


// Time: O(n), Space: O(depth of tree)
#define ll long long
class Solution {
public:
    unordered_map<ll,int> seen;
    int ans = 0, sum;

    void dfs(TreeNode* root, ll partialSum = 0) {
        partialSum += root->val;
        ans += seen[partialSum - sum];
        seen[partialSum]++;
        if (root->left) dfs(root->left, partialSum);
        if (root->right) dfs(root->right, partialSum);
        seen[partialSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        sum = targetSum;
        seen[0] = 1;
        if (root == nullptr) return ans;
        dfs(root);
        return ans;
    }
};