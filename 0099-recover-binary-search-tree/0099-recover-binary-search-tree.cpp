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
    void dfs(TreeNode * temp, vector<int> & ans){
        if(temp==nullptr){
            return;
        }
        dfs(temp->left, ans);
        ans.push_back(temp->val);
        dfs(temp->right,ans);

    }
    void newdfs(TreeNode * temp, vector<int>&ans,int &i){
        if(temp==nullptr){
            return;
        }
        
        newdfs(temp->left, ans,i);
        temp->val=ans[++i];
        newdfs(temp->right,ans,i);
    }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        TreeNode * temp=root;
         dfs(temp,ans);
       
         sort(ans.begin(),ans.end());
           for(auto i:ans){
            cout<<i<<endl;
         }
         int index=-1;
         newdfs(temp,ans,index);
    }
};