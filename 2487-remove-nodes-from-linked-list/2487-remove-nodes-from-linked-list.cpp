class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        if(head == NULL)
            return NULL;

        head->next = removeNodes(head->next);

        if(head->next != NULL && head->val < head->next->val) {
            return head->next;
        }

        return head;
    }
};