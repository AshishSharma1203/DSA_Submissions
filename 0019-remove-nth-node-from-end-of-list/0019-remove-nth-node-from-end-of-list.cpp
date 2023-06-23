/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:

        ListNode* removeNthbyCount(ListNode *head, int n)
        {

            if (head == NULL || head->next == NULL) return NULL;
            int count = 0;
           	// count the number of nodes
            for (ListNode *curr = head; curr != NULL; curr = curr->next)
            {
                count++;
            }
           	// find the position from start 
            count = count - n;

            if (count == 0)	// then we need to delete head node 
            {
                ListNode *curr = head;
                head = head->next;
                delete curr;
                return head;
            }

            int forward_count = 1;
            ListNode *curr = head;
            while (forward_count != count)
            {
                forward_count++;
                curr = curr->next;
            }
            ListNode *next = curr->next;
            curr->next = curr->next->next;
            delete next;
            return head;
        }

    ListNode* removeNthFromEnd(ListNode *head, int n)
    {
       	// Approach 1: counting nodes and deleting count-n th node from start 
       	// return removeNthbyCount(head, n);
       	// approach2: using single traversal

        if (head == NULL || head->next == NULL) return NULL;

        ListNode *slow = head, *fast = head;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
       	// check if fast is null it means  we need to delete head node 
        if (fast == nullptr)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

       	// else delete the required node 
        slow->next = slow->next->next;
        return head;
    }
};