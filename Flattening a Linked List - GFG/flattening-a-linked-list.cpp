// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
    
// approach 1:using bubble sort 
//   if(root==NULL || root->next==NULL) return root;

//   Node* curr1=root->next;
  
//   Node*curr2=root;
//   root->next=NULL;
//   while(curr2->bottom!=NULL) curr2=curr2->bottom;
   
//   while(curr1!=NULL)
//   {
       
//         Node* curr1_next = curr1->next;
//     curr1->next = NULL;
//     curr2->bottom = curr1;  // Updated: Change curr2->next to curr2->bottom
//     curr2 = curr2->bottom;  // Updated: Traverse the bottom pointer instead of next
//     while (curr2->bottom != NULL)
//         curr2 = curr2->bottom;
//     curr1 = curr1_next;
//   }
   
  
//   curr1=root;
//   int count=0;
//   while(curr1!=NULL)
//   {
//       count++;
//       curr1=curr1->bottom;
//   }
  
  
//   for (int i = 0; i < count - 1; i++) {
//         Node* curr = root;
//         for (int j = 0; j < count - i - 1; j++) {
//             if (curr->data > curr->bottom->data) {
//                 int temp = curr->data;
//                 curr->data = curr->bottom->data;
//                 curr->bottom->data = temp;
//             }
//             curr = curr->bottom;
//         }
//     }
  
//   return root;
  
 Node* merge(Node*curr1, Node*curr2)
 {
     
    Node* tail=new Node(0);
    Node* ans=tail;
    
    while(curr1!=NULL && curr2!=NULL)
    {
        if(curr1->data<curr2->data)
        {
            tail->bottom=curr1;
            curr1=curr1->bottom;
            tail=tail->bottom;
        }
        else
        {
            tail->bottom=curr2;
            curr2=curr2->bottom;
            tail=tail->bottom;
        }
    }
    if(curr1!=NULL)
    tail->bottom= curr1;
    
    else
     tail->bottom=curr2;
     
     return ans->bottom;
     
 }
   
    
Node *flatten(Node *root)
{
   // Your code here
   
 if(root==NULL || root->next==NULL) return root;
  
  root->next=flatten(root->next);
  
  Node* ans=merge(root,root->next);
  
  
  return ans;
 

}

