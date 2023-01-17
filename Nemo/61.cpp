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
        ListNode* saveNode = head;
        int num = 1;

        while(saveNode->next)
        {
            saveNode = saveNode->next;
            ++num;
        }

        saveNode->next = head;
        
        int realK = k % num;

        for(int i = 0; i < num - realK; ++i)
            saveNode = saveNode->next;
        
        ListNode* newHead = saveNode->next; 
        saveNode->next = nullptr;

        return newHead;
    }
};
