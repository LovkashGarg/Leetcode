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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        map<int, TreeNode*> m;
        int n = descriptions.size();
        map<TreeNode *,int>nodes;

        for (int i = 0; i < n; i++) {

            int parent = descriptions[i][0];
            int child = descriptions[i][1];

// create a parent 
            if (m.find(parent) == m.end()) {
                TreeNode* p = new TreeNode(parent);
                m[parent] = p;
            }

            if (descriptions[i][2] == 1) {
                // find if it exists or not
                if (m.find(child) != m.end()) {
                    m[parent]->left = m[child];
                } else {
                    TreeNode* temp = new TreeNode(child);
                    m[parent]->left = temp;
                    m[child] = temp;
                }
            } else {
                if (m.find(child) != m.end()) {
                    m[parent]->right = m[child];
                } else {
                    TreeNode* temp = new TreeNode(child);
                    m[parent]->right = temp;
                    m[child] = temp;
                }
            }

            nodes[m[child]]=1;
            nodes[m[parent]]=max(nodes[m[parent]],0);
        }

        for(auto i:nodes){
            if(i.second ==0){
                return i.first;
            }
        }
        return nullptr;
    }
};