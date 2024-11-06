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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
       long long int sum=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto temp=q.front();
                sum+=(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                 q.push(temp->right);
                }
            }
            if(q.size()==0){
            break;
            }
            else{
                sum=0;
            }
        }
        return sum;
    }
};