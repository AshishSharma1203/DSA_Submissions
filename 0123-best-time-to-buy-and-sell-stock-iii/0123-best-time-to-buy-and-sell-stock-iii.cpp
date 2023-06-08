class Solution
{
    public:

       	// Recursive approach 
        int solve(int i, bool buy, int count, vector<int> &prices)
        {

            if (i == prices.size() || count == 0)
                return 0;

            int profit;

            if (buy == false)
            {

                int buy = -prices[i] + solve(i + 1, true, count, prices);
                int not_buy = 0 + solve(i + 1, false, count, prices);
                profit = max(buy, not_buy);
            }
            else if (buy == true)
            {

                int retain = 0 + solve(i + 1, true, count, prices);
                int sell = prices[i] + solve(i + 1, false, count - 1, prices);
                profit = max(retain, sell);
            }

            return profit;
        }

   	// memoization approach  

    int mem_solve(int i, bool buy, int count, vector<int> &prices,  vector<vector<vector<int>>> &dp)
    {

        if (i == prices.size() || count == 0)
            return 0;

        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];

        int profit;

        if (buy == false)
        {

            int buy = -prices[i] + mem_solve(i + 1, true, count, prices, dp);
            int not_buy = 0 + mem_solve(i + 1, false, count, prices, dp);
            profit = max(buy, not_buy);
        }
        else if (buy == true)
        {

            int retain = 0 + mem_solve(i + 1, true, count, prices, dp);
            int sell = prices[i] + mem_solve(i + 1, false, count - 1, prices, dp);
            profit = max(retain, sell);
        }

        return dp[i][buy][count] = profit;
    }

    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        if (n == 0)
            return 0;

        int count = 2;
        bool buy = false;

        // vector<vector < int>> dp(n, vector<int> (2, -1));
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2, vector<int> (3,-1)));

        return mem_solve(0, buy, count, prices, dp);
    }
};