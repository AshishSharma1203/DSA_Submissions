class Solution
{
    public:
        bool solve(int i, int k, unordered_map<int, int> &mp, vector<int> &stones, vector< vector< int>> &dp)
        {
            if (i == stones.size() - 1)
                return true;

            if (dp[i][k] != -1)
                return dp[i][k];

            bool ans = false;
            bool way1 = false, way2 = false, way3 = false;

            if (mp.find(stones[i] + k - 1) != mp.end() && mp[stones[i] + k - 1] > i)
            {
                way1 = solve(mp[stones[i] + k - 1], k - 1, mp, stones, dp);
            }
            if (mp.find(stones[i] + k) != mp.end() && mp[stones[i] + k] > i)
            {
                way2 = solve(mp[stones[i] + k], k, mp, stones, dp);
            }
            if (mp.find(stones[i] + k + 1) != mp.end() && mp[stones[i] + k + 1] > i)
            {
                way3 = solve(mp[stones[i] + k + 1], k + 1, mp, stones, dp);
            }

            return dp[i][k] = way1 || way2 || way3;
        }

    bool canCross(vector<int> &stones)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < stones.size(); i++)
        {
            mp[stones[i]] = i;
        }
        if (stones[1] - stones[0] > 1)
            return false;

        vector<vector < int>> dp(stones.size(), vector<int> (stones.size(), -1));

        return solve(1, 1, mp, stones, dp);
    }
};