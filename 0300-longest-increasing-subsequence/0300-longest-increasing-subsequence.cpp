class Solution
{
    public:
       	// Recursive approach 
       	//         int solve(int i, int last, vector<int> &nums)
       	//         {

       	//             if (i == nums.size()) return 0;

       	//             int take = 0;
       	//             if (last == -1 || nums[i] > nums[last])
       	//             {
       	//                 take = 1 + solve(i + 1, i, nums);
       	//             }

       	//             int nontake = 0 + solve(i + 1, last, nums);

       	//             return max(take, nontake);
       	//         }

        int mem_solve(int i, int last, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (i == nums.size())
                return 0;
            if (dp[i][last + 1] != -1)
                return dp[i][last + 1];

            int take = 0;
            if (last == -1 || nums[i] > nums[last])
            {
                take = 1 + mem_solve(i + 1, i, nums, dp);
            }

            int nontake = 0 + mem_solve(i + 1, last, nums, dp);

            return dp[i][last + 1] = max(take, nontake);
        }

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector < int>> dp(n, vector<int> (n + 1, -1));

        return mem_solve(0, -1, nums, dp);
    }
};