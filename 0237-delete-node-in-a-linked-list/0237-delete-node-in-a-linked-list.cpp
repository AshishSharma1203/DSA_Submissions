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
        void deleteNode(ListNode *node)
        {

           	// approach : swap the value of curr node and next delete and then delete it 
            ListNode *curr = node;
            ListNode *curr_next = curr->next;

            swap(curr->val, curr_next->val);

            curr->next = curr_next->next;
            delete curr_next;
        }
};