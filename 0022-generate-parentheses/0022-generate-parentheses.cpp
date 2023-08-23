class Solution
{
    public:

        bool check(string s)
        {

            stack<char> st;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(')
                    st.push('(');

                else
                {
                    if (st.empty())
                        return false;
                    else if (st.top() != '(')
                        return false;

                    else st.pop();
                }
            }

            return st.empty() == true ? true : false;
        }

    void solve(int open, int close, string &temp, vector<string> &ans)
    {
        if (open == 0 && close == 0)
        {
            if (check(temp))
                ans.push_back(temp);
            return;
        }

        if (open > 0)
        {
            temp.push_back('(');
            solve(open - 1, close, temp , ans);
            temp.pop_back();
        }

        if (close > 0)
        {
            temp.push_back(')');
            solve(open, close - 1, temp , ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {

       	// int m = n;
       	// stack < char>st;
        vector<string> ans;
        string temp;

        solve(n, n, temp, ans);
        return ans;
    }
};