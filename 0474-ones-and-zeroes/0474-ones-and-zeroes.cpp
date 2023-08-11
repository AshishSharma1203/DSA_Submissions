class Solution
{
    public:

        void check(string s, int &c0, int &c1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '0') c0++;
                else c1++;
            }
        }

    int solve(int i, vector<string> &strs, int m, int n,map<pair<int,pair<int,int>>,int>&mp)
    {

        if (i < 0)
            return 0;

        if(mp.find({i,{m,n}})!=mp.end())
            return mp[{i,{m,n}}]; 

        int count0 = 0, count1 = 0;
        check(strs[i], count0, count1);

        if (count0 <= m && count1 <= n)
        {

            return mp[{i,{m,n}}]=   max(1 + solve(i - 1, strs, m - count0, n - count1,mp), solve(i - 1, strs, m, n,mp));
        }
        else
            return  mp[{i,{m,n}}] =solve(i - 1, strs, m, n,mp);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // {index,{m,n}}-->int 
       map<pair<int,pair<int,int>>,int>mp;
        return solve(strs.size() - 1, strs, m, n,mp);
    }
};