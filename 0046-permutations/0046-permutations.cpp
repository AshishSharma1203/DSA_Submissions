class Solution
{
    public:

        void solve(vector<int> &nums, vector<int> temp, vector< vector< int >> &ans, unordered_set< int > st)
        {
            if (temp.size() == nums.size())
            {
                ans.push_back(temp);
                return;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (st.find(nums[i]) == st.end())
                {
                    temp.push_back(nums[i]);
                    st.insert(nums[i]);
                    solve(nums, temp, ans, st);
                    temp.pop_back();
                    st.erase(nums[i]);
                }
            }
        }

    vector<vector < int>> permute(vector<int> &nums)
    {

        vector<int> temp;
        vector<vector < int>> ans;
        unordered_set<int> st;
        int n = nums.size();

        solve(nums, temp, ans, st);
        return ans;
    }
};