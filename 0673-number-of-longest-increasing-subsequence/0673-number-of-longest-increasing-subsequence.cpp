class Solution
{
    public:
        int findNumberOfLIS(vector<int> &nums)
        {

            int ans = 0;
            int n = nums.size();
            vector<vector < int>> dp(n, vector<int> (2, 1));	// dp[length, count]

            int maxLen = 1;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (nums[i] > nums[j])
                    {
                        if (dp[i][0] < dp[j][0] + 1)
                        {
                            dp[i][0] = dp[j][0] + 1;
                            dp[i][1] = dp[j][1];
                            maxLen = max(maxLen, dp[i][0]);
                        }
                        else if (dp[i][0] == dp[j][0] + 1)
                        {
                            dp[i][1] += dp[j][1];
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (dp[i][0] == maxLen)
                {
                    ans += dp[i][1];
                }
            }

            return ans;
        }
};