class Solution
{
    public:
        int minDistance(string word1, string word2)
        {

            int n = word1.length(), m = word2.length();

           	// find the LCS of both the strings  

           	// using tabulation method  

            vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {

                    if (word1[i - 1] == word2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
           	// cout<<dp[n][m];
           	// so required ans is sum of length of both strings - 2* LCS 
            int ans = n + m - (2 *dp[n][m]);

            return ans;
        }
};