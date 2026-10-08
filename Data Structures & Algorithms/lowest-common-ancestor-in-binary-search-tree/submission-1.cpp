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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        int pv, qv;

        if(p->val > q->val){
            pv = q->val;
            qv = p->val;
        } else {
            pv = p->val;
            qv = q->val;
        } 

        if(pv <= root->val && root->val <= qv){
            return root;
        }        
        else if(pv > root->val){
            ans = lowestCommonAncestor(root->right, p, q);
        }
        else if(qv < root->val){
            ans = lowestCommonAncestor(root->left, p, q);
        }
        return ans;
    }
};
