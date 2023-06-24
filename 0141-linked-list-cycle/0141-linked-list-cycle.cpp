/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {

           	// approach 1: modify the links and use a boolean attribute 
           	// approach 2: use a temp node and point nodes to it while traversing 
           	// Approach 3: use map;
           	//             unordered_set<ListNode*> st;
           	//             if (head == NULL || head->next == NULL) return false;
           	//             ListNode *curr = head;

           	//             while (curr != NULL)
           	//             {

           	//                 if (st.count(curr))
           	//                     return true;
           	//                 st.insert(curr);
           	//                 curr = curr->next;
           	//             }
           	//             return false;

           	// approach 4: using floyd algo of cycle detetction 
            if (head == NULL || head->next == NULL) return false;
            ListNode *slow = head, *fast = head;

            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) return true;
            }

            return false;
        }
};