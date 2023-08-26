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

        if (dp[i][last] != -1)
            return dp[i][last];

        int way1 = solve(i + 1, last, pairs, dp);
        int way2 = 0;
        if (last == 0  || pairs[last-1][1] < pairs[i][0])
        {

            way2 = 1 + solve(i + 1, i+1, pairs, dp);
        }
        return dp[i][last] = max(way1, way2);
    }

    int findLongestChain(vector<vector < int>> &pairs)
    {

        sort(pairs.begin(), pairs.end(), comp);
        int n = pairs.size();
        vector<vector < int>> dp(n, vector<int> (n+1, -1));
        return solve(0, 0, pairs, dp);
    }
};