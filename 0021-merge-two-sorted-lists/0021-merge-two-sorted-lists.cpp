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
        ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            
            if(list1==NULL) return list2;
            if(list2==NULL) return list1;
            
            ListNode * newcurr;
            ListNode *curr1 = list1;
            ListNode *curr2 = list2;

            if (curr1->val < curr2->val)
            {
                newcurr = new ListNode(curr1->val);
                curr1 = curr1->next;
            }
            else
            {
                newcurr = new ListNode(curr2->val);
                curr2 = curr2->next;
            }

            ListNode *ans = newcurr;

            while (curr1 != NULL && curr2 != NULL)
            {
                if (curr1->val < curr2->val)
                {
                    ListNode *temp = new ListNode(curr1->val);
                    newcurr->next = temp;
                    curr1 = curr1->next;
                    newcurr = newcurr->next;
                }
                else
                {
                    ListNode *temp = new ListNode(curr2->val);
                    newcurr->next = temp;
                    curr2 = curr2->next;
                    newcurr = newcurr->next;
                }
            }

            while (curr1 != NULL)
            {
                ListNode *temp = new ListNode(curr1->val);
                newcurr->next = temp;
                curr1 = curr1->next;
                newcurr = newcurr->next;
            }
            while (curr2 != NULL)
            {
                ListNode *temp = new ListNode(curr2->val);
                newcurr->next = temp;
                curr2 = curr2->next;
                newcurr = newcurr->next;
            }

            return ans;
        }
};