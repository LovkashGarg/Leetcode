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
    vector<vector<string>> printTree(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        int noofnodes=0;
        int value=1;
        int levels=0;
        while(!q.empty()){
             levels++;
            int n=q.size();

            for(int i=0;i<n;i++){
                auto temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                }
            }

            noofnodes+= value;
            value =value*2;
            //  cout<<noofnodes<<endl;
        }
        vector<vector<string>>ans(levels,vector<string>(noofnodes,""));
        int middleindex=noofnodes/2;
        queue<pair<TreeNode *,int>>newq;
        newq.push({root,middleindex});
        int level=0;
        while(!newq.empty()){
        
            int n=newq.size();
            for(int i=0;i<n;i++){
                TreeNode * temp=newq.front().first;
                int index=newq.front().second;
                ans[level][index]=to_string(temp->val);
                newq.pop();
                if(temp->left){
                    newq.push({temp->left,index-(pow(2,(levels-1-level-1) ) ) });
                }
                 if(temp->right){
                    newq.push({temp->right,index+(pow(2,(levels-1-level-1) ))});
                }
            }
            level++;
        }

        return ans;
    }
};