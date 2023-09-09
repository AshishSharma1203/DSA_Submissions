//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void convert(Node *head, TreeNode *&root);

void lvl(TreeNode *r) {
    if (r == NULL) return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left) q.push(j->left);
        if (j->right) q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}

/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        TreeNode *root = NULL;
        convert(head, root);
        if (root == NULL) cout << "-1\n";
        lvl(root);
        cout << endl;
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends


/*
The structure of Link list Node is as follows
struct Node
{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

//Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) 
{
    // Your code here
    
// Check if the linked list is empty
    if (head == NULL)
        return;

    // Create a queue for level order traversal
    queue<TreeNode*> q;

    // Initialize the root node with the data from the head of the linked list
    root = new TreeNode(head->data);

    // Enqueue the root node
    q.push(root);

    // Move to the next node in the linked list
    head = head->next;

    // Start the tree construction process
    while (head != NULL) 
    {
        // Dequeue a node from the queue
        TreeNode *current = q.front();
        q.pop();

        // Create left child node if available
        current->left = new TreeNode(head->data);

        // Enqueue the left child node
        q.push(current->left);

        // Move to the next node in the linked list
        head = head->next;

        // Create right child node if available
        if (head != NULL) {
            current->right = new TreeNode(head->data);

            // Enqueue the right child node
            q.push(current->right);

            // Move to the next node in the linked list
            head = head->next;
        }
    }
}

