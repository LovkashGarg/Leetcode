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
   long long int dfs(TreeNode * root, map<TreeNode *,long long int>&m){
        if(root==nullptr){
            return 0;
        }
        if(m.find(root)!=m.end()){
            return m[root];
        }
        long long int sum=root->val;
        long long int left=0,right=0;
        if(root->left){
         left=dfs(root->left,m);
         m[root->left]=left;
        }
        if(root->right){
          right=dfs(root->right,m);
          m[root->right]=right;
        }
       m[root]=sum+ left + right;
       return m[root];

    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<TreeNode *,long long int>m;
        long long int totalsum=dfs(root,m);
        vector<int>ans;
        map<long long int,int>sumcount;
        int maxcount=1;
        for(auto i: m){
            
            // cout<<i.first -> val << " "<<i.second<<endl;
            // ans.push_back()
            sumcount[i.second]++;
            // cout<<sumcount[i.second]<<endl;
            maxcount=max(maxcount,sumcount[i.second]);
        }

        for(auto i:sumcount){
            if(i.second==maxcount){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};