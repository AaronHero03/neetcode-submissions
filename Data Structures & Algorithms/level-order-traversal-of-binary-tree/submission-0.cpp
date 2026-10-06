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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int len = q.size();
            ans.push_back({});

            for(int i = 0; i < len; i++){
                ans[level].push_back(q.front()->val);

                if(q.front()->left != nullptr){
                    q.push(q.front()->left);
                }
                if(q.front()->right != nullptr){
                    q.push(q.front()->right);
                }

                q.pop();
            }
            level++;
        }

        return ans;
    }
};
