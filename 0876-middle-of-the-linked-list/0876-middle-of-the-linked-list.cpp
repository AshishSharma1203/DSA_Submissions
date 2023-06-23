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

        ListNode* middleNode(ListNode *head)
        {

           	// approach 1: count the node and then return middle  

           	//             if (head == NULL || head->next == NULL) return head;
           	//             int count = 0;

           	//             for (ListNode *curr = head; curr != NULL; curr = curr->next)
           	//             {
           	//                 count++;
           	//             }
           	//             count = (int) count / 2 + 1;

           	//             ListNode *curr = head;
           	//             while (count != 1)
           	//             {
           	//                 curr = curr->next;
           	//                 count--;
           	//             }

           	//             return curr;

           	// approach 2: using slow and fast pointers  
            
            if(head==NULL || head->next==NULL) return head;
            
            ListNode* slow=head, *fast= head;
            
            while(fast!=NULL && fast->next!=NULL)
            {
                fast=fast->next->next;
                slow=slow->next;
            }
            
            return slow;
            
        }
};