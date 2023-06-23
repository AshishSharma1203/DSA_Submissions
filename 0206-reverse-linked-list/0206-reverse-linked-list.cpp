/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        ListNode* reverseListRecursive(ListNode *curr, ListNode *prev)
        {

            if (curr == NULL)
                return prev;

            ListNode *curr_next = curr->next;
            curr->next = prev;

            return reverseListRecursive(curr_next, curr);
        }

    ListNode* reverseList(ListNode *head)
    {

        if (head == NULL || head->next == NULL) return head;

        ListNode *curr = head, *prev = NULL;

       	// recursive code

        return reverseListRecursive(curr, prev);

       	//            	// Iterative code  
       	//             while (curr != NULL)
       	//             {

       	//                 ListNode *curr_next = curr->next;
       	//                 curr->next = prev;
       	//                 prev = curr;
       	//                 curr = curr_next;
       	//             }

       	//             return prev;
    }
};