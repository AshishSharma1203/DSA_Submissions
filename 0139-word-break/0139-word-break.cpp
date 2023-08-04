class Solution
{
    public:
        bool MCM(int i, int j, string &s, unordered_set<string> &dict, vector<vector< int>> &dp)
        {
            if (i > j)
            {
                return false;
            }

            string temp = s.substr(i, j - i + 1);
            if(dp[i][j] != -1)
            return dp[i][j];
            if (dict.find(temp) != dict.end())
            {
                return true;
            }
            bool ans = false;
            for (int k = i; k <= j - 1; k++)
            {

                bool left = MCM(i, k, s, dict,dp);
                bool right = MCM(k + 1, j, s, dict,dp);

                if (left && right)
                {
                    ans = true;
                }
            }
            return dp[i][j] = ans;
        }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int i = 0, j = n - 1;
        vector<vector < int>> dp(n, vector<int> (n, -1));
        return MCM(i, j, s, dict,dp);
    }
};