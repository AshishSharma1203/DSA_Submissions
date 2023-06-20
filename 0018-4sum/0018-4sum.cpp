class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
           	// to keep only unique qudrauplets sort the vector and then insert 
           	// brute force use four loops 
           	// optimal : using hashing 
           	// better : use two pointer 
int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int a = nums[i], b = nums[j];
            long long  curr_sum = a + b;
            long long req_sum = target - curr_sum;

            int low = j + 1, high = n - 1;

            while (low < high)
            {
                int c = nums[low];
                int d = nums[high];
                if (c + d == req_sum)
                {
                    vector<int> temp = {a, b, c, d};
                    ans.push_back(temp);

                    low++;
                    high--;

                    while (low < high && nums[low] == nums[low - 1])
                        low++;
                    while (low < high && nums[high] == nums[high + 1])
                        high--;
                }
                else if (c + d > req_sum)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
    }
    return ans;
        }
};