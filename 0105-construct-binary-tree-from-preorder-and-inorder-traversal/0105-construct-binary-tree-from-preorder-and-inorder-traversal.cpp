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
    TreeNode * solve(int prestart,int preend,int instart,int inend,vector<int>& preorder, vector<int>& inorder, map<int,int>&inordermap){
        if(prestart> preend || instart > inend){
            return nullptr;
        }

        // find the root in map
        int index= inordermap[preorder[prestart]];

        int leftelements= index- instart;

        TreeNode *temp= new TreeNode(preorder[prestart]);

        temp->left=solve(prestart+1,  prestart + leftelements  , instart,index-1 ,preorder,inorder,inordermap );
        temp->right= solve(prestart + leftelements +1 , preend, index +1, inend,preorder,inorder, inordermap);

        return temp;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         map<int,int>inordermap;
         int n=preorder.size();
         for(int i=0;i<n;i++){
            inordermap[inorder[i]]=i;
         }
         return solve(0,n-1,0,n-1,preorder,inorder,inordermap);
    }
};