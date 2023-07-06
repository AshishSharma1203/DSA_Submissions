class Solution
{
    public:
        int minSubArrayLen(int target, vector<int> &nums)
        {
           	// brute force  use two nested loop
           	//             int ans = INT_MAX;
           	//             int n = nums.size();
           	//             for (int i = 0; i < n; i++)
           	//             {
           	//                 int sum = 0;
           	//                 for (int j = i; j < n; j++)
           	//                 {

           	//                     sum += nums[j];
           	//                     if (sum >= target)
           	//                     {

           	//                         ans = min(ans, j - i + 1);
           	//                         break;
           	//                     }
           	//                 }
           	//             }
           	//             return ans == INT_MAX ? 0 : ans;

            int left = 0, right = 0;
            int ans = INT_MAX;
            int n = nums.size();
            int sum = 0;
            while (right < n)
            {

                int currsum = sum + nums[right];

                if (currsum < target)
                {
                    sum = currsum;
                }
                else
                {

                    while (currsum >= target)
                    {
                        ans = min(ans, right - left + 1);
                        currsum = currsum - nums[left];
                        left++;
                    }
                    sum = currsum;
                }
                right++;
            }
            return ans == INT_MAX ? 0 : ans;
        }
};