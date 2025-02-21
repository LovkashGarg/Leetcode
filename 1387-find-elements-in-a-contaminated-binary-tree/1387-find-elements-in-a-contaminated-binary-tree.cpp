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
class FindElements {
public:
int index=0;
map<int,int>m;
   void solve(int index,TreeNode *root){
    if(root==nullptr){
        return ;
    }

    root->val= index;
    m[index]=1;
    solve(2*index+1, root->left);
    solve(2*index+2, root->right);

   }
    FindElements(TreeNode* root) {
        solve(index,root);
    }
    
    bool find(int target) {
        
return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */