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
    ListNode* rotateRight(ListNode* head, int k) {

    if(head==nullptr || head->next==nullptr){
        return head;
    }


      stack<ListNode *>  s;
      ListNode *temp=head;
      int n=0;
      while(temp){
        s.push(temp);
        temp=temp->next;
        n++;
      }

      k=k%n;

      // now here 
      while(k--){
         // take last node 
     ListNode *temp= s.top();
         s.pop();
    s.top()->next=nullptr;
         temp->next=head;
         head=temp;
      }
      return head;
    }
};