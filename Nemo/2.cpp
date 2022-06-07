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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* t3 = new ListNode(0);
        ListNode* cur = t3;
        
        int sum = 0;
        int save = 0;
        
        while(l1 || l2 || save > 0)
        {
            sum = save;
            
            if (l1)
            {
             sum += l1->val;
             l1 = l1->next;
            }
            if (l2)
            {
             sum += l2->val;
             l2 = l2->next;
            }            
                     
            save = sum / 10;
            cur->next = new ListNode(sum % 10);   
            cur = cur->next;
        }
        return t3->next;
    }
};
