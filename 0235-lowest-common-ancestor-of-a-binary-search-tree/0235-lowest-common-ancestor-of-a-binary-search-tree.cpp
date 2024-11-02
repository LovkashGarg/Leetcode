/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
     void bfs(TreeNode *root, TreeNode *p,vector<TreeNode *>&path){
        if(root==nullptr){
            return;
        }
        if(root==p){
        path.push_back(root);
            return ;
        }
        else if(root->val > p->val){
            path.push_back(root);
            bfs(root->left,p,path);
        }
        else{
            path.push_back(root);
            bfs(root->right,p,path);
        }
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *>path1;
        bfs(root,p,path1);
        vector<TreeNode *>path2;
        bfs(root,q,path2);
        TreeNode *ans=nullptr;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i]==path2[i]){
                ans=path1[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};