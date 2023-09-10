class Solution
{
    public:

        void solve(int i, vector<int> &temp, vector<vector< int >> &ans, vector< int > &candidates, int target)
        {

            if (i == candidates.size())
            {

                if (target == 0)
                {
                    ans.push_back(temp);
                }
                return;
            }

            if (target == 0)
            {
                ans.push_back(temp);
                return;
            }
            if (candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                solve(i, temp, ans, candidates, target - candidates[i]);
                temp.pop_back();
            }

            solve(i + 1, temp, ans, candidates, target);
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> temp;

        solve(0, temp, ans, candidates, target);
        return ans;
    }
};