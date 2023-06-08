class Solution
{
    public:

       	// recursive approach 
        int solve(int i, bool bought, vector<int> &prices)

    {

        if (i >= prices.size()) return 0;

        int profit = 0;

        if (bought == false)
        {

            int buy = -prices[i] + solve(i + 1, true, prices);
            int not_buy = solve(i + 1, false, prices);

            profit = max(buy, not_buy);
        }
        else if (bought == true)
        {
            int retain = 0 + solve(i + 1, true, prices);
            int sell = prices[i] + solve(i + 2, false, prices);
            profit = max(retain, sell);
        }

        return profit;
    }

    int maxProfit(vector<int> &prices)
    {

        bool bought = false;
       	// recursive approach 
       	// return solve(0, bought, prices);

       	// tabulation approach 
int n= prices.size();
        vector<vector < int>> dp(n + 2, vector<int> (2, 0));
        dp[n][0] = dp[n][1] = dp[n + 1][0] = dp[n + 1][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            for (int bought = 0; bought <= 1; bought++)
            {

                int profit;

                if (bought == 0)
                {

                    int buy = -prices[i] + dp[i + 1][1];
                    int not_buy = dp[i + 1][0];

                    profit = max(buy, not_buy);
                }
                else if (bought == 1)
                {
                    int retain = 0 + dp[i + 1][1];
                    int sell = prices[i] + dp[i + 2][0];
                    profit = max(retain, sell);
                }

                dp[i][bought] = profit;
            }
        }

       	// our ans will be  returned as solve(0,0,prices), thereofre return dp[0][0];
        return dp[0][0];
    }
};