class Solution
{
    public:
        int firstMissingPositive(vector<int> &nums)
        {

            unordered_set<int> st;
            int maxi = INT_MIN;

            for (int i = 0; i < nums.size(); i++)
            {
                st.insert(nums[i]);
                maxi = max(maxi, nums[i]);
            }
if(maxi<=0)
    return 1;
            int ans = INT_MIN;
            for (int i = 1; i <= maxi; i++)
            {
                if (st.find(i) == st.end())
                {
                    ans = i;
                    break;
                }
            }
            if (ans == INT_MIN)
                return maxi + 1;
            return ans;
        }
};