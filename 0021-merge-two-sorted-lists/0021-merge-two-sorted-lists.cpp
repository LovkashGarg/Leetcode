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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        else if(list2==nullptr){
            return list1;
        }

        ListNode * temp1=list1;
        ListNode*temp2=list2;
        ListNode * head;
        ListNode *truehead;
        if(list1->val > list2-> val){
          head=list2;
          temp2=temp2->next;
          truehead=list2;
        }
        else{
            head=list1;
            temp1=temp1->next;
            truehead=list1;
        }

        while(temp1 !=nullptr && temp2!=nullptr){
            cout<<temp1->val << " "<<temp2->val<<endl;
            if(temp1->val <=temp2->val){
                head->next=temp1;
                head=head->next;
                temp1=temp1->next;
            }
            else{
                head->next=temp2;
                 head=head->next;
                temp2=temp2->next;
            }
        }
        if(temp1!=nullptr){
            head->next=temp1;
        }

        if(temp2!=nullptr){
            head->next=temp2;
        }
        
        return truehead;
    }
};