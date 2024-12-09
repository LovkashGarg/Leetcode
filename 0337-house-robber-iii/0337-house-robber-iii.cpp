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
unordered_map<TreeNode *,int>m;
int solve(TreeNode *root){
    if(root==nullptr){
        return 0;
    }
    if(m.find(root)!=m.end()){
        return  m[root];
    }
    if(root->left ==nullptr && root->right==nullptr){
        return root->val;
    }
    // include 
    int include1 =root->val;
    int include2=root->val;
    int include3=root->val;
    int include4=root->val;
    if(root->left){
        include1+=solve(root->left->left);
        include2+=solve(root->left->right);
    }
    if(root->right){
        include3+=solve(root->right->left);
        include4+=solve(root->right->right);
    }
    int include= include1 + include2 + include3 + include4 -3*root->val;
    int exclude1=0;
    int exclude2=0;

    exclude1=solve(root->left);
    exclude2=solve(root->right);
    int exclude= exclude1+ exclude2;
    return  m[root]=max(include,exclude);
    
}
    int rob(TreeNode* root) {

        return solve(root);
    }
};