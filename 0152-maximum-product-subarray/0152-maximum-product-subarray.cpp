class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            if (nums.size() == 1)
                return nums[0];
            int ans = 0;

            int prefix_product = 0;

            for (auto i: nums)
            {

                if (prefix_product == 0)
                {
                    prefix_product = i;
                }
                else
                    prefix_product *= i;

                ans = max(prefix_product, ans);
            }

            int suffix_product = 0;

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (suffix_product == 0)
                {
                    suffix_product = nums[i];
                }
                else
                    suffix_product *= nums[i];

                ans = max(ans, suffix_product);
            }

            return ans;
        }
};