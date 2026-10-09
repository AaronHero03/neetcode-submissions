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

    void dfs(TreeNode* root, int maxV, int& ans){
        if(root == nullptr) return;
        if(root->val >= maxV){
            maxV = root->val;
            ans++;
        }

        dfs(root->left, maxV, ans);
        dfs(root->right, maxV, ans);

        return;
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxV = root->val;
        dfs(root, maxV, ans);
    
        return ans;
    }
};
