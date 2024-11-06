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
   map<int,int>m;
    void solve(TreeNode *root,int index){
        if(root==nullptr){
            return ;
        }
        root->val=index;
        m[index]=1;
        solve(root->left,2*index+1);
        solve(root->right,2*index+2);
    }

    FindElements(TreeNode* root) {
        

        // here recovering 
        
        solve(root,0);

    }
    
    bool find(int target) {
        // do a dfs traversal since 
         return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */