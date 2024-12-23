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
    int minimumOperations(TreeNode* root) {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        // time complexicity is O(1*(1^2) + 2*(4^2))
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                auto temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            // no I have to check no of swaps
            // find minimum elements
            for (int i = 0; i < n; i++) {
                int val = level[i];
                int mini = level[i];
                int index = -1;
                for (int j = i + 1; j < n; j++) {
                    // find minimum
                    if(mini>level[j]){
                    mini = level[j];
                    index = j;
                    }
                }

                if (val != mini) {
                    swap(level[i], level[index]);
                    count++;
                }
            }
            level.clear();
        }
        return count;
    }
};