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
    int height(TreeNode* node, bool& balanced){
        if(node == nullptr) return 0;
        if(balanced == false ) return 0;

        int leftHeight = height(node->left, balanced);
        int rightHeight = height(node->right, balanced);    

        if(abs(leftHeight - rightHeight) >= 2){ 
            balanced = false;            
        }

        return (max(leftHeight, rightHeight) + 1);
    }
    

    bool isBalanced(TreeNode* root) {
        bool balanced = true;

        height(root, balanced);

        return balanced;
    }
};
