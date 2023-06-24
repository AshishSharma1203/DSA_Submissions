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


     /* brute force approach  
       vector<int> v;
        
        // if(head==NULL){
        //     return true; 
        // }
        
        while(head!=NULL){
        
            v.push_back(head->val);
            head=head->next;
            
        }
        int n=v.size();
        for(int i=0;i<v.size()/2;i++){
            
            if(v[i]!=v[n-i-1]){
                return false; 
            }
            
        }
        
    return true;
    */

class Solution {
public:
    
    
    bool isPalindrome(ListNode* head) {
       
        
        // using two pointer approach  
        
        if(head==NULL){
            return true; 
        }
        
       ListNode* slow= head, *fast=head,*prev=NULL,*temp=NULL;
       
         
        
        while( fast &&  fast->next ){
            
             fast=fast->next->next;
            temp=slow;
            
            slow=slow->next;
            temp->next=prev;
            prev=temp;
            
		// fast = fast -> next -> next,
		// tmp = slow -> next, slow -> next = prev, prev = slow, slow = tmp;      
            
        }
   
        // if no of nodes is odd 
        
        if(fast==NULL)
        {
            
            // slow=slow->next;
            
            while(slow!=NULL){
                if(slow->val !=prev->val ){
                    return false;
                }
                
                slow=slow->next;
                prev=prev->next;
            }
            
        }
        
        // else no of nodes is even 
        else
        {
         slow=slow->next;   
               while(slow!=NULL){
                if(slow->val !=prev->val ){
                    return false;
                }
                
                slow=slow->next;
                prev=prev->next;
            }
            
            
        }
        
        return true; 
   
    }
    
};