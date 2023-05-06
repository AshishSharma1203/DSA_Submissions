class Solution
{
    public:
       	// Recursive approach 
        int solve(int i, vector<int> &coins, int amount)
        {
            if (amount == 0)
                return 1;
            if (i == 0)
            {
                if (amount % coins[0] == 0)
                {
                    return 1;
                }
                else
                    return 0;
            }

            if (coins[i] <= amount)
            {
                return solve(i, coins, amount - coins[i]) + solve(i - 1, coins, amount);
            }
            else
                return solve(i - 1, coins, amount);
        }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

       	// return solve(n - 1, coins, amount);

       	// tabulation approach 

        vector<vector < int>> dp(n, vector<int> (amount + 1, 0));

        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int j = 0; j < n; j++)
            dp[j][0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i] <= j)
                    dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n - 1][amount];
    }
};