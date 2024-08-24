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
class Solution{
public:
void preorder(vector<TreeNode *>&pre, TreeNode *root){
    if(root==nullptr){
        return;
    }
    preorder(pre,root->left);
    pre.push_back(root);
    preorder(pre,root->right);
}
    bool isValidBST(TreeNode* root) {
        
    //   writing the preorder
     vector<TreeNode *> temp;
     preorder(temp,root);
     for(int i=1;i<temp.size();i++){
        if(temp[i-1]->val >=temp[i] ->val){
            return false;
        }
     }
     return true;

    }
};