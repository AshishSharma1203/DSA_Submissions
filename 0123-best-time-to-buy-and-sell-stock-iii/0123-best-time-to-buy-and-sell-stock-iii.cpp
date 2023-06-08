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

    int mem_solve(int i, bool buy, int count, vector<int> &prices, vector<vector< vector< int>>> &dp)
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
       	// recursive 
       	// vector<vector < int>> dp(n, vector<int> (2, -1));

        vector<vector<vector< int>>> dp(n+1, vector<vector < int>> (2, vector<int> (3, -1)));	// (index,buy,count)
       	// memoization 
        return mem_solve(0, buy, count, prices, dp);

       	// tabulation approach 

        for (int i = 0; i <= 2; i++)
        {
            dp[n][0][i] = 0;
            dp[n][1][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                dp[i][j][0] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int count = 1; count <= 2; count++)
                {

                    int profit;

                    if (buy == false)
                    {

                        int buy = -prices[i] +  dp[i+1][1][count];
                        int not_buy = 0 + dp[i+1][0][count];
                        profit = max(buy, not_buy);
                    }
                    else if (buy == true)
                    {

                        int retain = 0 + dp[i+1][1][count];
                        int sell = prices[i] + dp[i+1][0][count-1] ;
                        profit = max(retain, sell);
                    }

                     dp[i][buy][count] = profit;
                }
            }
        }
        
        return dp[0][0][count];
        
    }
};