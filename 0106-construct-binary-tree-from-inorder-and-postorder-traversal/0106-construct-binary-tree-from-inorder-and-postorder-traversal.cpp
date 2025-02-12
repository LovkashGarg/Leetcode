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
    TreeNode *solve(int poststart,int postend,int instart,int inend, vector<int> & postorder,vector<int>&inorder,map<int,int>&inordermap){
        
        if(instart> inend || poststart> postend){
            return nullptr;
        }

int index=inordermap[postorder[postend]];
 TreeNode *temp= new TreeNode (postorder[postend]);
      int leftelements= index- instart;
        
        temp->left= solve(poststart, poststart+ leftelements-1, instart,index-1, postorder,inorder,inordermap);
        temp->right= solve(poststart + leftelements , postend-1, index+1,inend,postorder,inorder,inordermap);
        return temp;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        map<int,int>inordermap;
        for(int i=0;i<n;i++){
            inordermap[inorder[i]]=i;
        }

        return solve(0,n-1,0,n-1,postorder,inorder,inordermap);
    }
};