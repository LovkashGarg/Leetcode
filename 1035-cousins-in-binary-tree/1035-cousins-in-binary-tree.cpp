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
    bool isCousins(TreeNode* root, int x, int y) {
        

        // we have two node as cousins if they have the same level 
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            bool flagx=false;
            bool flagy=false;
            TreeNode *parentx=nullptr;
            TreeNode *parenty=nullptr;

            for(int i=0;i<n;i++){

                auto t=q.front();
                q.pop();
              
                if(t->left){
                    if(t->left->val == x ){
                        parentx=t;
                         flagx=true;
                    }
                    if(t->left->val==y){
                        parenty=t;
                        flagy=true;
                    }
                    q.push(t->left);
                    
                }
                
                if(t->right){

                     if(t->right->val == x ){
                        parentx=t;
                         flagx=true;
                    }
                    if(t->right->val==y){
                        parenty=t;
                        flagy=true;
                    }
                    q.push(t->right);
                }
            }
            if(flagx==true && flagy==true && parentx !=parenty){
                return true;
            }

        }
        return false;
    }
};