class Solution
{
    public:
        int numSubarrayProductLessThanK(vector<int> &nums, int k)
        {

            int n = nums.size(), ans = 0;

            for (int i = 0; i < n; i++)
            {

                int curr_product = 1;
                for (int j = i; j < n; j++)
                {

                    curr_product *= nums[j];
                    if (curr_product < k)
                    {
                        ans++;
                    }
                    else
                        break;
                }
            }

            return ans;
        }
};