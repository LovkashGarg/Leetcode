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
    ListNode* partition(ListNode* head, int x) {
        ListNode * temp=head;
        vector<int>greaters;
        vector<int>smallers;
        while(temp){
          if(temp->val>=x){
          greaters.push_back(temp->val);
          }
          else {
           smallers.push_back(temp->val);
          }
          temp=temp->next;
        }

        int n1=smallers.size();
        int n2=greaters.size();
        temp=head;
        int i=0;
        while(i<n1){
            temp->val=smallers[i];
            temp=temp->next;
            i++;
        }
        int j=0;
        while(j<n2){
             temp->val=greaters[j];
            temp=temp->next;
            j++;
        }
return head;
    }
};