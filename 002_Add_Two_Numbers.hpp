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
        bool isOverheaded = false;
        int sum = 0;
        ListNode* head = new ListNode();
        ListNode* current = head;
        
        ListNode* currentL1 = l1;
        ListNode* currentL2 = l2;
        
        while (currentL1 != nullptr || currentL2 != nullptr)
        {
            if (!(currentL1 == l1 && currentL2 == l2))
            {
                current->next = new ListNode();
                current = current->next;
            }
            sum = 0;

            if (currentL1)
            {
                sum += currentL1->val;
                currentL1 = currentL1->next;
            }
            if (currentL2)
            {
                sum += currentL2->val;
                currentL2 = currentL2->next;
            }
            if (isOverheaded)
            {
                ++sum;
            }
            
            isOverheaded = sum > 9;
            
            if (isOverheaded)
            {
                current->val = sum % 10;
            }
            else
            {
                current->val = sum;
            }
        }
        
        if (isOverheaded)
        {
            current->next = new ListNode(1);
        }
        
        return head;
    }
};
