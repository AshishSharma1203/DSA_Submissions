class Solution
{
    public:

        int solve(int i, bool last, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (i >= nums.size())
                return 0;
            if (dp[i][last] != -1)
                return dp[i][last];
            if (last == false)
            {
                return dp[i][last] = max((nums[i] + solve(i + 1, true, nums, dp)), solve(i + 1, false, nums, dp));
            }
            else
                return dp[i][last] = solve(i + 1, false, nums, dp);
        }

    int rob(vector<int> &nums)
    {

       	// bool last = false;
       	// vector<vector < int>> dp(nums.size(),vector < int>(2,-1));
       	// return solve(0, last, nums, dp);
        int n = nums.size();
        vector<vector < int>> dp(n + 1, vector<int> (2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= 1; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = max(nums[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                else
                    dp[i][j] = dp[i + 1][0];
            }
        }

        return dp[0][0];
    }
};