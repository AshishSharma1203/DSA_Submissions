class Solution
{
    public:

        void solve(int i, string digits, string &temp, vector<string> &ans, unordered_map<char, string> &mp)
        {
            if (digits.size() == temp.size())
            {
                ans.push_back(temp);
                return;
            }

            string alpha = mp[digits[i]];
            for (int j = 0; j < alpha.size(); j++)
            {

                char ch = alpha[j];
                temp.push_back(ch);

                solve(i + 1, digits, temp, ans, mp);
                temp.pop_back();
            }
        }

    vector<string> letterCombinations(string digits)
    {

       	if (digits.size() == 0)
       	{
       	    vector<string> ans;
       	    return ans;
       	}

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string temp = "";
        vector<string> ans;

        solve(0, digits, temp, ans, mp);

        return ans;
    }
};