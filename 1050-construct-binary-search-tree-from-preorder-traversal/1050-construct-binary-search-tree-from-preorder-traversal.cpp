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
    TreeNode *construct(vector<int>& preorder,vector<int>&nge, int start ,int end , int n ){

        if(start > end){
            return nullptr;
        }
        TreeNode *root= new TreeNode(preorder[start]);
        // now find the next greater element 
        root->left= construct(preorder, nge, start+1,nge[start]-1,n);
        root->right= construct(preorder, nge, nge[start],end,n);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        stack<int>s;
        int n=preorder.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&& preorder[i] >= preorder[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                nge[i]=s.top();
            }
            else{
                nge[i]=n;
            }
            s.push(i);
        }

        return construct(preorder, nge , 0,n-1,n);

    }
};