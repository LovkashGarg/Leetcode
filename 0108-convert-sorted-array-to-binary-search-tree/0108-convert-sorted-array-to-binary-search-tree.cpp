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
     TreeNode * solve(int start,int end,vector<int>&nums){
        if(start >end){
            return nullptr;
        }
        
        int mid=(start+end)/2;

        TreeNode *temp= new TreeNode(nums[mid]);
        temp->left= solve(start,mid-1,nums);
        temp->right= solve(mid+1,end,nums);

        return temp;
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end= n-1;
        return solve(start,end,nums);
    }
};