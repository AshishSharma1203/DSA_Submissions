class Solution
{
    public:

        int solve(vector<int> &nums)
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

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> nums1 = nums, nums2 = nums;

       	// dont take last element
        nums1.erase(nums1.begin() + n - 1);
       	// dont take first element
        nums2.erase(nums2.begin());

        int ans = max(solve(nums1), solve(nums2));
        return ans;
    }
};