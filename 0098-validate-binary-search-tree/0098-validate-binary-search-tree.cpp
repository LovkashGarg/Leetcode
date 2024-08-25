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
     bool isValid(TreeNode* root,long long int leftrange,long long int rightrange){
        if(root==nullptr){
            return true;
        }
        if(root->val <=leftrange || root->val >=rightrange){
            return false;
        }
         return isValid(root->left,leftrange,root->val) && isValid(root->right,root->val,rightrange);
     }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};