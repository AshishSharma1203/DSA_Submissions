class Solution
{
    public:

        static bool comp(vector<int> &a, vector<int> &b)
        {
            return a[0] < b[0];
        }

    int solve(int i, int last, vector<vector < int>> &pairs, vector< vector< int>> &dp)
    {

        if (i >= pairs.size())
            return 0;

        if (dp[i][last + 1] != -1)
            return dp[i][last + 1];

        int way1 = solve(i + 1, last, pairs, dp);
        int way2 = 0;
        if (last == -1 || pairs[last][1] < pairs[i][0])
        {

            way2 = 1 + solve(i + 1, i, pairs, dp);
        }
        return dp[i][last + 1] = max(way1, way2);
    }

    int findLongestChain(vector<vector < int>> &pairs)
    {

        sort(pairs.begin(), pairs.end(), comp);
        int n = pairs.size();
       	// vector<vector < int>> dp(n, vector<int> (n + 1, -1));
       	// return solve(0, -1, pairs, dp);

        vector<vector < int>> dp(n+1, vector<int> (n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {

            for (int last = i - 1; last >= -1; last--)
            {

                int way1 = dp[i + 1][last + 1];
                int way2 = 0;

                if (last == -1 || pairs[last][1] < pairs[i][0])
                    way2 = 1 + dp[i + 1][i + 1];

                dp[i][last + 1] = max(way1, way2);
            }
        }

        return dp[0][0];
    }
};