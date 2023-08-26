class Solution
{
    public:

        int find(vector<int> &A, int k)
        {

            int start = 0;
            int len = 0;
            int ans = 0, n = A.size();

            for (int i = 0; i < n; ++i)
            {
                if (i == 0) len++;
                else
                {
                    int dif = (A[i] - A[i - 1]) - 1;
                    k -= dif;
                    while (k < 0)
                    {
                        k += ((A[start + 1] - A[start]) - 1);
                        len--;
                        start++;
                    }
                    len++;
                }
                ans = max(ans, len);
            }

            return ans;
        }

    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, vector < int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ans = 1;

        for (auto it: mp)
        {
            vector<int> v = it.second;
            int curr_ans = find(v, k);
            ans = max(ans, curr_ans);
        }

        return ans;
    }
};