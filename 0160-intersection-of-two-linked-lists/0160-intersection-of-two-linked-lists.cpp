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
        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
        {
           	// approach 1: using hashing 

           	//        unordered_set<ListNode*> st;

           	//         for(ListNode* curr=headA;curr!=NULL;curr=curr->next)
           	//         {

           	//             st.insert(curr);

           	//         }

           	//         for(ListNode *curr =headB;curr!=NULL;curr=curr->next)
           	//         {
           	//             if(st.count(curr)) return curr;
           	//         }

           	//         return NULL;

           	// Efficient appraoch 

            int count1 = 0, count2 = 0;
            for (ListNode *curr = headA; curr != NULL; curr = curr->next)
            {
                count1++;
            }
            for (ListNode *curr = headB; curr != NULL; curr = curr->next)
            {
                count2++;
            }
            ListNode* curr1=headA, *curr2=headB;
            if(count1>count2)
            {
                int dx=count1-count2;
                for(int i=1;i<=dx;i++)
                    curr1=curr1->next;
            }
            else if(count1<count2)
            {
                 int dx=count2-count1;
                for(int i=1;i<=dx;i++)
                    curr2=curr2->next;
            }
            
            while(curr1!=NULL && curr2!=NULL)
            {
                if(curr1==curr2) return curr1;;
                curr1=curr1->next;
                curr2=curr2->next;
            }
            
            return NULL;
        }
};