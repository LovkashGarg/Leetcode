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
    bool bfs(TreeNode *root){
        if(root==nullptr){
            return true;
        }
        queue<TreeNode *>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>level;

            for(int i=0;i<n;i++){
    
                auto temp=q.front();
                q.pop();

                if(temp->left){
                    q.push(temp->left);
                    level.push_back(temp->left->val);
                }
                else{
                    level.push_back(INT_MIN);
                }

                if(temp->right){
                    q.push(temp->right);
                    level.push_back(temp->right->val);
                }
                else{
                    level.push_back(INT_MIN);
                }

            }
           
            for(int i=0;i<ceil(level.size()/2.0);i++){
                    cout<<level[i]<<" "<<level[level.size()-i-1]<<endl;
                   if(level[i]!=level[level.size()-i-1]){
                     return false;
                   }
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return bfs(root);
    }
};