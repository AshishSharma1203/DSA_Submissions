class Solution
{
    public:

        bool solve(int i, vector<int> &nums, vector<int> &dp)
        {

            int n = nums.size();
            if (i >= nums.size() - 1)
                return true;
            if (dp[i] != -1)
                return dp[i];

            int max_steps = min(nums[i], n - 1);
            bool ans = false;
            for (int j = 1; j <= max_steps; j++)
            {
                ans = ans || solve(i + j, nums, dp);
            }

            return dp[i] = ans;
        }

    bool canJump(vector<int> &nums)
    {

       	// approach 1: 
       	//         int max_step=0, curr_step=0;
       	//         for(int i=0;i < nums.size();i++)
       	//         {
       	//             int curr_step=nums[i];
       	//             max_step=max(max_step,curr_step);

       	//             max_step--;

       	//             if(max_step < 0 && i < nums.size()-1)
       	//             return false;
       	//         }

       	//         return true;

       	// approach 2 :dp 

        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};