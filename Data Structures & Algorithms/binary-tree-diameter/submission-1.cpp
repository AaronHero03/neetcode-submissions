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
    int maxDiameter = 0;
    int dfs(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int leftHeight = dfs(node->left);
        int rightHeight = dfs(node->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return (1 + max(leftHeight, rightHeight));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return maxDiameter;
    }
};
