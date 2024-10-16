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
    void solve(TreeNode *root,int targetSum,vector<int>&path, vector<vector<int>>& Allpaths){
        if(root==nullptr){
            return;
        }
        // means sum equal and also the leaf node 
        if(targetSum-root->val==0 && root->left==nullptr && root->right==nullptr){
            path.push_back(root->val);
            Allpaths.push_back(path);
            path.pop_back();
            return;
        }
//  cout<<root->val<<" "<<targetSum<<endl;
        // include exclude principal
        // if(targetSum-root->val >0){
            path.push_back(root->val);
          solve(root->left,targetSum-root->val, path, Allpaths);
          solve(root->right,targetSum-root->val, path, Allpaths);
            path.pop_back();
        // }
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return {};
        }
        if(root->left==nullptr && root->right==nullptr && root->val == targetSum){
            return {{root->val}};
        }
        vector<vector<int>>Allpaths;
        vector<int>path;
        path.push_back(root->val);
       solve(root->left,targetSum-root->val,path,Allpaths);
       solve(root->right,targetSum-root->val,path,Allpaths);
        return Allpaths;
    }
};