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
    bool isPalindrome(ListNode* head) {
        vector<int>list;
        ListNode * temp=head;
        while(temp){
            list.push_back(temp->val);
            temp=temp->next;
        }
        int n=list.size();
        if(n==1){
            return true;
          }
        for(int i=0;i<(n/2);i++){
            // cout<<i<<endl;
            if(list[i]!=list[n-i-1]){
                return false;
            }
        }
        return true;
    }
};