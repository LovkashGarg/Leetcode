/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
        while (!q.empty()) {
            int n = q.size();
            // means this is a odd level
            queue<TreeNode*> t;
            vector<int> level;
            if (lev % 2 == 0) {
                t = q;
            }
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                    if(lev%2==0){
                    level.push_back(temp->left->val);
                    }
                }

                if (temp->right) {
                    q.push(temp->right);
                    if(lev%2==0){
                    level.push_back(temp->right->val);
                    }
                }
            }

            if (lev % 2 == 0) {
                reverse(level.begin(), level.end());
                int j = 0;
                int n = t.size();
                for (int i = 0; i < n; i++) {
                    auto temp = t.front();
                    t.pop();
                    if (temp->left) {
                        temp->left->val = level[j++];
                    }

                    if (temp->right) {
                        temp->right->val = level[j++];
                    }
                }
            }
            level.clear();
            lev++;
        }
        return root;
    }
};