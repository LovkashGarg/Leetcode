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
    void dfs(TreeNode *root, vector<string>&ans,string path){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
             path+=to_string(root->val);
            // path+='->';
            ans.push_back(path);
            return;
        }

          path+=to_string(root->val);
          path+="->";
         dfs(root->left,ans,path);
         dfs(root->right,ans,path);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string path;
        dfs(root,ans,path);
        return ans;
    }
};