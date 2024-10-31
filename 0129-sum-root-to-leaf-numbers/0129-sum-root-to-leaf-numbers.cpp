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
    int ans=0;
    void solve(TreeNode *root,string s){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
           
                // cout<<s<<endl;
                s+=root->val+'0';
                ans+=stoi(s);
            
                // cout<<ans<<endl;
            return;
        }
        // if(root->left==nullptr && root->right==nullptr){
               
        // }
        char d=root->val+'0';
        solve(root->left,s+ d);
        solve(root->right,s+ d);

    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        string s;
         solve(root,s);
         return ans;
    }
};