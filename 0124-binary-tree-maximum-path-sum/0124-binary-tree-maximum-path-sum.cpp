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
    int maxi=INT_MIN;
    int maxPath(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        // since  negative cant give me a max path 
        // would fail for ex 
        //  15
        //  / \
        // 10 20 
         //   / \
        //  -30 -16


// negative doesnot give us a max path
        int left=max(0,maxPath(root->left));
        int right=max(0,maxPath(root->right));

        maxi=max(maxi,left+right+ root->val);

        // this line would make our path to be continous 
        return root->val + max(left,right);

    }
    int maxPathSum(TreeNode* root) {
        int ans=maxPath(root);
        return maxi;
    }
};