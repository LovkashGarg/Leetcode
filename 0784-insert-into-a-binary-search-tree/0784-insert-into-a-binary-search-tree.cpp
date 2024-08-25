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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // here 4 cases
        if(root==nullptr){
            TreeNode * temp=new TreeNode(val);
            return temp;
        }
        // 0 child
        else if(root->left ==nullptr && root->right==nullptr){
            if(root->val >val){
                TreeNode * temp=new TreeNode(val);
                root->left=temp;
            }
            else{
                TreeNode * temp=new TreeNode(val);
                root->right=temp;
            }
        }
        // 1 child
        else if(root->left ==nullptr && root->right!=nullptr){
            TreeNode * temp=new TreeNode(val);
              if(root->val >val){
                root->left=temp;
              }
              else{
                root->right=insertIntoBST(root->right,val);
              }
        }
          else if(root->left !=nullptr && root->right==nullptr){
            TreeNode * temp=new TreeNode(val);
              if(root->val <val){
                // right vali node bna do 
                root->right=temp;
              }
              else{
                root->left=insertIntoBST(root->left,val);
              }
        }
        // 2 child 
        else{
            if(root->val >val){
            root->left=insertIntoBST(root->left,val);
            }
            else{
            root->right=insertIntoBST(root->right,val);
            }
        }
     return root;
    }
};