class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return head;
        
        ListNode* temp = head;
        while(temp->next)
        {
            int tempInt = temp->val;
            temp->val = temp->next->val;
            temp->next->val = tempInt;
            if(temp->next->next)
                temp =  temp->next->next;
            else
                break;
        }
        return head;
        
    }
};
