/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* detectCycle(ListNode *head)
        {

               if (head == NULL || head->next == NULL)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Find meeting point
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // Step 2: Check for no cycle
    if (fast == NULL || fast->next == NULL)
        return NULL;

    // Step 3: Find the starting node of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
        }
};