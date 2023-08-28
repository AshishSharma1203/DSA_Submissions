/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        
        ListNode* curr=dummy;
        ListNode* prev_curr=NULL;
        
        for(int i=0;i<left;i++)
        {
            
            prev_curr=curr;
            curr=curr->next;
            
        }
        
        ListNode* rev_end=curr;
        ListNode * prev_rev_end=prev_curr;
        
        for(int i=left;i<=right;i++)
        {
            
            ListNode * forward=rev_end->next;
            rev_end->next=prev_rev_end;
            prev_rev_end=rev_end;
            rev_end=forward;
            
        }
        
        prev_curr->next= prev_rev_end;
        curr->next=rev_end;
        
        return dummy->next;
        
    }
};