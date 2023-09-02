class Solution
{
    public:

        int solve(int i, vector<int> &nums, vector<int> &dp)
        {

            if (i >= nums.size() - 1)
                return 0;

            if (dp[i] != -1)
                return dp[i];

            int ans = INT_MAX - 1;

            int max_steps = min(nums[i], (int) nums.size() - 1);

            for (int j = 1; j <= max_steps; j++)
            {

                ans = min(ans, 1 + solve(i + j, nums, dp));
            }

            return dp[i] = ans;
        }

    int jump(vector<int> &nums)
    {

        int n = nums.size();
       	//         vector<int> dp(n, -1);

       	//         return solve(0, nums, dp);

       	// tabulation  

        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            int max_steps = min(nums[i], n - 1);

            for (int j = 1; j <= max_steps; j++)
            {
                if (i + j < n)
                {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }

        return dp[0];
    }
};