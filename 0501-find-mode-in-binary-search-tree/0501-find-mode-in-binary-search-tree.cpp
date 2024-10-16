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
    int currfreq=0, maxfreq=0, preele=INT_MIN;
    vector<int>res;
    void dfs(TreeNode *root, unordered_map<int,int>&m,int &maxfrq){
        if(root==nullptr){
            return;
        }
        

        dfs(root->left,m,maxfrq);
        m[root->val]++;
        maxfrq=max(maxfrq,m[root->val]);
        dfs(root->right,m,maxfrq);
    }
    void inorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(preele==root->val){
        currfreq++;
    }
    else{
        currfreq=1;
    }

    if(currfreq >maxfreq){
        res.clear(); // to clear all the element 
        res.push_back(root->val);
        maxfreq=currfreq;
    }
    else if(currfreq==maxfreq){
        res.push_back(root->val);
    }
    preele=root->val;
    inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
       // inorder travesal
      inorder(root);
       return res;
    }
};