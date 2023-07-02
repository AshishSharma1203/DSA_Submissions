class Solution
{
    public:

        void solve(int i, vector<int> temp, vector<vector< int>> &ans)
        {

            if (i == temp.size())
            {
                ans.push_back(temp);
                return;
            }

            for (int j = i; j < temp.size(); j++)
            {

                swap(temp[i], temp[j]);
                solve(i + 1, temp, ans);
                swap(temp[i], temp[j]);
            }
        }

    vector<vector < int>> permute(vector<int> &nums)
    {

        vector<int> temp = nums;
        vector<vector < int>> ans;

        solve(0, temp, ans);
        return ans;
    }
};