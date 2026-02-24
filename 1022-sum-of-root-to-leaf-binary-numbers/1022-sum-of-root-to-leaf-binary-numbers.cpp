class Solution {
public:
    void solve(TreeNode* root, int &ans, int val) {
        if(root == NULL) return;

        val = val * 2 + root->val;   // Build binary directly

        if(root->left == NULL && root->right == NULL) {
            ans += val;
            return;
        }

        solve(root->left, ans, val);
        solve(root->right, ans, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        solve(root, ans, 0);
        return ans;
    }
};