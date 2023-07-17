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

        ListNode* reverse(ListNode *head)
        {
            ListNode *curr = head;
            ListNode *prev = nullptr;

            while (curr != nullptr)
            {
                ListNode *curr_next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = curr_next;
            }

            return prev;
        }

    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        l1 = reverse(l1);
        l2 = reverse(l2);

        int carry = 0;
        ListNode *ans = new ListNode(0);
        ListNode *tail = ans;

        while (carry || l1 || l2)
        {
            int currsum = carry;

            if (l1 != nullptr)
            {
                currsum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                currsum += l2->val;
                l2 = l2->next;
            }

            carry = currsum / 10;
            currsum %= 10;

            tail->next = new ListNode(currsum);
            tail = tail->next;
        }

        ListNode *result = reverse(ans->next);
        return result;
    }
};