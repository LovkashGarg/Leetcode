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
    int widthOfBinaryTree(TreeNode* root) {
// bfs traversal
// first is the node and second is the index of that node 
        queue<pair<TreeNode *,long long int>>q;

        q.push({root,0});
       long long int ans=0;
        while(!q.empty()){
           int n=q.size();
           long long start=q.front().second;
           long long end=q.back().second;
        
           ans=max(ans,end-start+1);
            for(int i=0;i<n;i++){

                TreeNode *temp=q.front().first;
                // main statement 
            long long int index=q.front().second-start;
            // cout<<temp->val<<" "<<index<<endl;
                q.pop();
             
                if(temp->left){
                    q.push({temp->left,(long long)2*index+1});
                }

                if(temp->right){
                    q.push({temp->right,(long long)2*index+2});
                }
            } 
        }
        return ans;    
    }
};