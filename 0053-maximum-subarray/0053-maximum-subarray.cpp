class Solution
{
    public:

        void solve(int i, int n, int curr, vector<int> &nums, int &ans)
        {
            if (i == n)
            {
                ans = max(ans, curr);
                return;
            }

           	// Include the current element in the subarray
            solve(i + 1, n, curr + nums[i], nums, ans);

           	// Start a new subarray from the current element
            solve(i + 1, n, nums[i], nums, ans);

           	// Update the answer with the maximum value so far
            ans = max(ans, curr);
        }

    int maxSubArray(vector<int> &nums)
    {
       	// appraoch 1 
       	// use two for loops 

       	//         int ans=INT_MIN;
       	//         int n= nums.size();
       	//         for(int i=0;i < n;i++)
       	//         {

       	//             int curr_sum=0;
       	//             for(int j=i;j < n;j++)
       	//             {
       	//                 curr_sum+=nums[j];
       	//                 ans=max(ans,curr_sum);
       	//             }

       	//         }
       	//         return ans; 

       	// approach 2

       	// recursive approach 
        int n = nums.size();
       	// int ans = INT_MIN;
       	// solve(0, n, 0, nums, ans);
       	// return ans;

       	// Kadane's Algo 
        int ans = INT_MIN;
        int curr_ans = 0;

        for (int i = 0; i < n; i++)
        {

            curr_ans = max(nums[i] + curr_ans, nums[i]);
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};