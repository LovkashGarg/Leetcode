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
    bool dfs(TreeNode *root,unordered_map<int,int>&m,int k){
        if(root==nullptr){
            return false;
        }
        m[root->val]++;

        if(m[k-root->val]>=1){
            if((k-root->val)==root->val && m[root->val] <=1){      
            return dfs(root->left,m, k) || dfs(root->right,m,k);;
            }
            return true;     
        }

        return dfs(root->left,m, k) || dfs(root->right,m,k);
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode *temp=root;
        unordered_map<int,int>m;
        return dfs(root,m,k);
    }
};