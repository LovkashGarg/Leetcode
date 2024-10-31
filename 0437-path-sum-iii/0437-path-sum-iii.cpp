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
int ans=0;
// main catch is to do dfs traversal for each node 

void solve(TreeNode *root,int targetSum,long long int sum){
      if(root==nullptr){
        return;
    }
    sum+=root->val;

    if(sum == targetSum){
        // cout<<root->val<<endl;
        ans+=1;
    }

    solve(root->left,targetSum,sum);
    solve(root->right,targetSum,sum);
 
}
void dfs(TreeNode *root,int targetSum){
    if(root==nullptr){
        return;
    }
     long long int sum=0;
    solve(root,targetSum,sum);
    dfs(root->left,targetSum);
    dfs(root->right,targetSum);
}
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return 0;
        }
        // do a dfs traversal for each node 
      
       dfs(root,targetSum);
        return ans;
    }
};