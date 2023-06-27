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
    ListNode* rotateRight(ListNode* head, int k) {
      
        if(head==NULL || head->next==NULL) return head;
        ListNode* fast=head;
        ListNode* slow=head;
      
        // int count++;
        int nodecount=0;
        for(ListNode* curr=head;curr!=NULL;curr=curr->next)
        {
            nodecount++;
            
            
        }
        k =k%nodecount;
        
        for(int count=1;count<=k;count++ )
        {
            fast=fast->next;
            // if(fast==NULL)
            //     fast=head; 
            // // to handl when k is greatr than 
        }
        // do check if fast==head then the reversed list will be same 
        if(fast==head) return head;
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* ans=slow->next;
        slow->next=NULL;
        fast->next=head;
        return ans;
        
    }
};