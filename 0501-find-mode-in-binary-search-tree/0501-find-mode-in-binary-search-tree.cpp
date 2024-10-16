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
    void dfs(TreeNode *root, unordered_map<int,int>&m,int &maxfrq){
        if(root==nullptr){
            return;
        }
        

        dfs(root->left,m,maxfrq);
        m[root->val]++;
        maxfrq=max(maxfrq,m[root->val]);
        dfs(root->right,m,maxfrq);
    }
    vector<int> findMode(TreeNode* root) {
       // inorder travesal
       unordered_map<int,int>m;
       int maxfrq;
       dfs(root,m,maxfrq); 
       vector<int>ans;
       for(auto i:m){
        if(i.second==maxfrq){
           ans.push_back(i.first);
        }
       }
       return ans;
    }
};