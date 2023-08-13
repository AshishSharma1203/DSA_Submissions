class Solution
{
    public:

        bool solve(int i, vector<int> &nums, vector<int> &dp)
        {

            int n = nums.size();
            if (i >= n)
                return true;
            if (dp[i] != -1)
                return dp[i];

            bool ans = false;
            bool way1 = false, way2 = false, way3 = false;

            if (i <= n - 2 && nums[i] == nums[i + 1])
                way1 = solve(i + 2, nums, dp);
            if (i <= n - 3 && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
                way2 = solve(i + 3, nums, dp);
            if (i <= n - 3 && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
                way3 = solve(i + 3, nums, dp);

            ans = way1 || way2 || way3;
            return ans;
        }

    bool validPartition(vector<int> &nums)
    {
       	// vector<int> dp(nums.size(), -1);
       	// return solve(0, nums, dp);
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            bool ans = false;
            bool way1 = false, way2 = false, way3 = false;

            if (i <= n - 2 && nums[i] == nums[i + 1])
                way1 = solve(i + 2, nums, dp);
            if (i <= n - 3 && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
                way2 = solve(i + 3, nums, dp);
            if (i <= n - 3 && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2])
                way3 = solve(i + 3, nums, dp);

            ans = way1 || way2 || way3;
            dp[i] = ans;
        }
        return dp[0];
    }
};