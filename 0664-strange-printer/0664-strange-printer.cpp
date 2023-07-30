class Solution
{
    public:

        int MCM(int i, int j, string s, vector<vector < int>> &dp)
        {

            if (i == j)
                return 1;
           	// if (i > j)
           	//     return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            int ans = INT_MAX;
           	// int leftcut = 0, rightcut = 0;

            for (int k = i; k <= j - 1; k++)
            {
                if (dp[i][k] == -1)
                    dp[i][k] = MCM(i, k, s, dp);

                if (dp[k + 1][j] == -1)
                    dp[k + 1][j] = MCM(k + 1, j, s, dp);
               	// int rightcut = MCM(k + 1, j, s,dp);
                ans = min(ans, dp[i][k] + dp[k + 1][j]);
            }

            return dp[i][j] = (s[i] == s[j]) ? ans - 1 : ans;
        }

    int strangePrinter(string s)
    {

        int n = s.size();
        vector<vector < int>> dp(n, vector<int> (n, -1));
        return MCM(0, n - 1, s, dp);
    }
};