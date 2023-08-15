/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* partition(ListNode *head, int x)
        {
              // ls-. lessStart, le--less end , gs---greaterStart, g-->greater end 
            ListNode *ls = NULL, *le = NULL, *gs = NULL, *ge = NULL;

            for (ListNode *curr = head; curr != NULL; curr = curr->next)
            {

                if (curr->val < x)
                {
                    if (ls == NULL)
                    {
                        ls = le = curr;
                    }
                    else
                    {
                        le->next = curr;
                        le = le->next;
                    }
                }
                else
                {

                    if (gs == NULL)
                    {
                        gs = ge = curr;
                    }
                    else
                    {
                        ge->next = curr;
                        ge = ge->next;
                    }
                }
            }

            if (ls == NULL)
            {
               	// If there are no elements less than x, return the list of elements greater than or equal to x
                return gs;
            }

            le->next = gs;
            if (ge != NULL)
            {
               	// Make sure to terminate the list of elements greater than or equal to x
                ge->next = NULL;
            }

            return ls;
        }
};