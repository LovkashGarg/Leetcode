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
    int pairSum(ListNode* head) {
        
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        int n=temp.size();
         int maxi=1;
        for(int i=0;i<n/2;i++){
            maxi=max(maxi,temp[i]+ temp[n-i-1]);
        }
        return maxi;
    }
};