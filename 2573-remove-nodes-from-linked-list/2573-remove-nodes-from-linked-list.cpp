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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        
        // find next greater element 
        vector<int>nums;
        ListNode *temp=head;
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }

        stack<int>s;
        int n=nums.size();
        vector<int> nge(n);
        for(int i= n-1;i>=0;i--){
            // jab tak ye element bda hai pop out 
           while(!s.empty() && nums[s.top()] <= nums[i]){
            s.pop();
           }
           if(s.empty()){
            nge[i]=n;
           }
           else{
            nge[i]=s.top();
           }
           s.push(i);
        }

      head=nullptr;
      temp=new ListNode(-1);
        for(int i=0;i<n;i++){
         if(nge[i]==n){
            ListNode *node= new ListNode(nums[i]);
           if(head==nullptr){
            head=node;
           }

           temp->next=node;
           temp=node;
          }
        }

        return head;
    }
};