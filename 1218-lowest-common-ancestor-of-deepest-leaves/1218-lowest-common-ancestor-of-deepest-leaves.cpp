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
     TreeNode *lca(TreeNode *root,TreeNode *p,TreeNode *q){
        if(root==nullptr || root==p || root==q){
            return root;
        }

        TreeNode *left=lca(root->left,p,q);
        TreeNode *right=lca(root->right,p,q);

        if(left==nullptr){
            return right;
        }
        else if(right==nullptr){
            return left;
        }
        else{
            return root;
        }
     }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        vector<TreeNode *>level;
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                auto temp=q.front();
                level.push_back(temp);
                // cout<<temp->val<<endl;
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(q.size()!=0){
level.clear();
            }
        }

        // Now find lca of this nodes;
        // single nodes is itself its lca
        if(level.size()==1){
            return level[0];
        }
        else{
            TreeNode *ans=level[0];
            for(int i=1;i<level.size();i++){
                ans=lca(root,ans,level[i]);
            }
            return ans;
        }
    }
};