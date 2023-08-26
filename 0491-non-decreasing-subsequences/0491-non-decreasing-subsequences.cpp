class Solution
{
    public:

        void solve(int i, int last, vector<int> &temp, vector<vector< int >> &ans, vector< int > &nums, set< vector< int>> &st)
        {

            if (i == nums.size())
            {
                if (temp.size() >= 2 && st.find(temp) == st.end())
                {
                    st.insert(temp);
                    ans.push_back(temp);
                }
                return;
            }

            solve(i + 1, last, temp, ans, nums, st);

            if (last == -1 || nums[i] >= nums[last])
            {
                temp.push_back(nums[i]);
                solve(i + 1, i, temp, ans, nums, st);
                temp.pop_back();
            }
        }

    vector<vector < int>> findSubsequences(vector<int> &nums)
    {

        int last = -1;
        set<vector < int>> st;
        vector<vector < int>> ans;
        vector<int> temp;
        solve(0, last, temp, ans, nums, st);

        return ans;
    }
};