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
        stack<ListNode *>s;
        ListNode *temp=head;
        while(temp){
            s.push(temp);
            temp=temp->next;
        }
          int maxi=INT_MIN;
        while(!s.empty()){
          if(maxi> s.top()->val){
            s.top()->val=-1;
          }
          maxi=max(maxi,s.top()->val);
          s.pop();
        }
       ListNode *temp1=new ListNode(-1);
       ListNode *temp2=head;
       head=nullptr;
       while(temp2){
        if(temp2->val!=-1){
            if(head==nullptr){
                head=temp2;
            }
            temp1->next=temp2;
            temp1=temp1->next;
        }
        temp2=temp2->next;
       }
       
        return head;
    }
};