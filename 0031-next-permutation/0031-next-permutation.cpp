class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {

            int n = nums.size(), break_point = -1;

            for (int i = n - 2; i >= 0; i--)
            {

                if (nums[i] < nums[i + 1])
                {
                    break_point = i;
                    break;
                }
            }
            
            if (break_point == -1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }

            for (int i = n - 1; i >break_point; i--)
            {
                if (nums[i] > nums[break_point])
                {
                    swap(nums[i], nums[break_point]);
                    break;
                }
            }

            sort(nums.begin() + break_point+1, nums.end());
            return;
        }
};