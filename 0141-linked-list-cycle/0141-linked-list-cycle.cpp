/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
            unordered_set<ListNode*> st;
            if (head == NULL || head->next == NULL) return false;
            ListNode *curr = head;

            while (curr != NULL)
            {

                if (st.count(curr))
                    return true;
                st.insert(curr);
                curr = curr->next;
            }
            return false;
        }
};