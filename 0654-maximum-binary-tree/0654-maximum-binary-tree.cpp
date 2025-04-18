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
    TreeNode *construct(vector<int>& nums, int start ,int end){
        if(start > end){
            return nullptr;
        }
         int index=-1;
         int maxi=INT_MIN;
        for(int i=start;i<=end;i++){
          if(maxi<nums[i]){
            maxi=nums[i];
            index=i;
          }
        }

        TreeNode *root= new TreeNode(nums[index]);
        root->left= construct(nums, start, index-1);
        root->right= construct(nums, index+1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int n= nums.size();
        return construct(nums,0,n-1);
    }
};