class MyStack
{
    public:
        queue<int> q;
    MyStack()
    {

       	// queue<int> q;?
    }

    void push(int x)
    {

        queue<int> temp;
        while (q.empty() == false)
        {
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (temp.empty() == false)
        {
            q.push(temp.front());
            temp.pop();
        }
    }

    int pop()
    {

        if (q.empty())
            return -1;

        int a = q.front();
        q.pop();
        return a;
    }

    int top()
    {

        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 *Your MyStack object will be instantiated and called as such:
 *MyStack* obj = new MyStack();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->top();
 *bool param_4 = obj->empty();
 */