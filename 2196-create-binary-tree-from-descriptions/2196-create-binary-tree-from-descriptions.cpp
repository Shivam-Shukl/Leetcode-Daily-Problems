/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int, bool> mp;
        unordered_map<int, TreeNode*> nodeMap;

        int n = des.size();

        for (int i = 0; i < n; i++) {
            int parent = des[i][0];
            int child = des[i][1];
            int isLeft = des[i][2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = false;
            }

            mp[child] = true;

            if (nodeMap.find(parent) == nodeMap.end()) {
                nodeMap[parent] = new TreeNode(parent);
            }

            if (nodeMap.find(child) == nodeMap.end()) {
                nodeMap[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                nodeMap[parent]->left = nodeMap[child];
            } else {
                nodeMap[parent]->right = nodeMap[child];
            }
        }

        TreeNode* root = nullptr;

        for (auto& it : mp) {
            if (it.second == false) {
                root = nodeMap[it.first];
                break;
            }
        }

        return root;
    }
};