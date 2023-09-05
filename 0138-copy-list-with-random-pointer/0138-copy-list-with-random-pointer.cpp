/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
if (!head) return NULL;

    unordered_map<Node*, Node*> mp;

    Node* curr = head;
    Node* new_head = NULL;

    while (curr) {
        Node* temp = NULL;

        // Check if the current node already has a corresponding copy in the map
        if (mp.find(curr) != mp.end()) {
            temp = mp[curr];
        } else {
            temp = new Node(curr->val);
            mp[curr] = temp; // Map the original node to its copy
        }

        // Set the new head if it's not set yet
        if (!new_head) {
            new_head = temp;
        }

        // Handle next and random pointers
        if (curr->next) {
            if (mp.find(curr->next) != mp.end()) {
                temp->next = mp[curr->next];
            } else {
                temp->next = new Node(curr->next->val);
                mp[curr->next] = temp->next;
            }
        }

        if (curr->random) {
            if (mp.find(curr->random) != mp.end()) {
                temp->random = mp[curr->random];
            } else {
                temp->random = new Node(curr->random->val);
                mp[curr->random] = temp->random;
            }
        }

        curr = curr->next;
    }

    return new_head;
        }
};