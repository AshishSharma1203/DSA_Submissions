class LRUCache
{
    public:

        class node
        {
            public:
                int key;
            int val;
            node * next;
            node * prev;
            node(int _key, int _val)
            {
                key = _key;
                val = _val;
                next = NULL;
                prev = NULL;
            }
        };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)

    {
         node* temp = head->next;
    newnode->next = temp;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;

        // node *temp = head->next;
        // newnode->next = temp;
        // temp->prev = head;
        // head->next = newnode;
        // temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {

        node *del_prev = delnode->prev;
        node *del_next = delnode->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
        // delete(delnode);
    }
    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {

        if (m.find(key) != m.end())
        {

            node *currnode = m[key];
            m.erase(key);
            deletenode(currnode);
        }

        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node *temp = new node(key, value);
        addnode(temp);
        m[key] = head->next;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */