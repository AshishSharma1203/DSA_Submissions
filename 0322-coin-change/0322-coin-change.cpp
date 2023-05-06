class Solution
{
    public:

        int solve(int i, vector<int> &coins, int amount, vector<vector < int>> &dp)
        {
            if(amount==0)
                return 0;
           
            if (i == 0)
            {

                if (amount % coins[i] == 0)
                    return amount / coins[i];
                else
                    return 1e9;
            }
            
            
            
            if (dp[i][amount] != -1)
                return dp[i][amount];

            if (coins[i] <= amount)
            {
                int take = 1 + solve(i, coins, amount - coins[i],dp);
                int nontake = solve(i - 1, coins, amount,dp);

                return dp[i][amount] = min(take, nontake);
            }

            return dp[i][amount] = solve(i - 1, coins, amount,dp);
        }

    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<vector < int>> dp(n, vector<int> (amount + 1, -1));
        int ans = solve(n - 1, coins, amount, dp);
        return ans == 1e9 ? -1 : ans;
      
    }
};