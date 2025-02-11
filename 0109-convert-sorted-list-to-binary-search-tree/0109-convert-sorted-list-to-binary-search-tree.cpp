/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    if(start>end){
        return nullptr;
    }
    int mid= (start+ end)/2;

    TreeNode *temp = new TreeNode(nums[mid]);
    temp->left= solve(start,mid-1,nums);
    temp->right= solve(mid+1,end,nums);
    return temp;
}

    TreeNode* sortedListToBST(ListNode* head) {
          
          vector<int>nums;
          while(head){
            nums.push_back(head->val);
            head=head->next;
          }

          // Now here 
          int n=nums.size();
          return solve(0,n-1,nums);
    }

};
