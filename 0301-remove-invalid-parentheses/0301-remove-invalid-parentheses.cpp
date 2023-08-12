class Solution
{
    public:

        int isValid(string s)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                char top = st.empty() ? '/' : st.top();
                if (s[i] == ')' && top == '(')
                    st.pop();
                else if (s[i] == ')' || s[i] == '(')
                    st.push(s[i]);
            }
            return st.size();
        }
    unordered_set<string> ans;
    unordered_set<string> allString;
    void solve(string s, int minDeletion)
    {
        
        if (allString.find(s) != allString.end())
            return;
        allString.insert(s);
        if (minDeletion == 0)
            if (!isValid(s))
                ans.insert(s);

        for (int i = 0; i < s.size(); i++)
        {

            string newString = s.substr(0, i) + s.substr(i + 1);
            solve(newString, minDeletion - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        int minDeletion = isValid(s);
        cout << minDeletion;

        solve(s, minDeletion);

        vector<string> temp;
        for(auto it:ans)
            temp.push_back(it);
        return temp;
    }
};