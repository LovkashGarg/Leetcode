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
    long long kthLargestLevelSum(TreeNode* root, int k) {
         queue<TreeNode *>q;
         q.push(root);
         priority_queue<long long int>pq;
         int level=0;
         while(!q.empty()){
            int n=q.size();
           long long int levelsum=0;
            level++;
            for(int i=0;i<n;i++){  
        auto top=q.front();
            q.pop();
            levelsum+=top->val;
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
            }
            // cout<<levelsum<<endl;
            pq.push(levelsum);   
         }
           if(level <k){
            return -1;
         }
         int i=1;
         while(i<k){
            i++;
            // cout<<pq.top()<<endl;
            pq.pop();
         }
       
         return pq.top();
    }
};