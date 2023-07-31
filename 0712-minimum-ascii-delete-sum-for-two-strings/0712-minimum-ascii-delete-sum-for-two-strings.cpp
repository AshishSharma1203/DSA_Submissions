class Solution
{
    public:

        int solve(int i, int j, string &s1, string &s2, vector<vector < int>> &dp)
        {
            if (i == s1.size() && j == s2.size())
                return 0;

            if (i == s1.size() && j != s2.size())
            {
                int sum = 0;
                while (j != s2.size())
                {
                    sum += (int) s2[j];
                    j++;
                }
                return sum;
            }
            if (j == s2.size() && i != s1.size())
            {
                int sum = 0;
                while (i != s1.size())
                {
                    sum += (int) s1[i];
                    i++;
                }
                return sum;
            }

            if (dp[i][j] != -1)
                return dp[i][j];

            if (s1[i] == s2[j])
            {
                return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
            }
            else
            {
                int s1_del = (int) s1[i] + solve(i + 1, j, s1, s2, dp);
                int s2_del = (int) s2[j] + solve(i, j + 1, s1, s2, dp);
                return dp[i][j] = min(s1_del, s2_del);
            }
        }

    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};