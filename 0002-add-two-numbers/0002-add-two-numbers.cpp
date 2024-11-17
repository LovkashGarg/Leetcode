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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        //  res->next=new ListNode();
        int carry = 0;
        ListNode *Head = new ListNode();
        Head->next = res;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val + l2->val + carry >= 10)
            {
                res->val = ((l1->val + l2->val + carry) % 10);
                cout << res->val << endl;
                carry = 1;
                res->next = new ListNode();
                res = res->next;
                 if(l1->next==NULL && l2->next==NULL){
                    break;
                }
                
            }
            else
            {
                res->val = ((l1->val + l2->val + carry));
                cout << res->val << endl;
                carry = 0;
                if(l1->next==NULL && l2->next==NULL){
                    break;
                }
                res->next = new ListNode();
                res = res->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 != NULL)
        {
            while (l2 != NULL)
            {
                if (l2->val + carry >= 10)
                {
                    res->val = ((l2->val + carry) % 10);
                    cout << res->val << endl;
                    carry = 1;
                          res->next = new ListNode();
                       res = res->next;
                    if(l2->next==NULL){
                        break;
                    }
                }
                else
                {
                    res->val = (l2->val + carry);
                    cout << res->val << endl;
                    carry = 0;
                    if(l2->next==NULL){
                        break;
                    }
                    res->next = new ListNode();
                    res = res->next;
                }
                l2 = l2->next;
            }
        }
        else if (l1 != NULL && l2 == NULL)
        {
            while (l1 != NULL)
            {
                if (l1->val + carry >= 10)
                {
                    res->val = ((l1->val + carry) % 10);
                    // cout << res->val << endl;
                    carry = 1;
                     res->next = new ListNode();
                    res = res->next;
                    if(l1->next==NULL){ 
                        break;
                    }
                }
                else
                {
                    res->val = (l1->val + carry);
                    // cout << res->val << endl;
                    carry = 0;
                    if(l1->next==NULL){
                        break;
                    }
                    res->next = new ListNode();
                    res = res->next;
                }
                l1 = l1->next;
            }
        }
        if (carry == 1)
        {
            res->val = (carry);
            cout << 1 << endl;
        }
        return Head->next;
    }  
};