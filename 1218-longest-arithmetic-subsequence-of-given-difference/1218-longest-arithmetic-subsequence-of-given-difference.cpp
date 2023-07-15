class Solution
{
    public:

        int solve(int i, int last, vector<int> &arr, int difference, vector<vector< int>> &dp)
        {

            if (i == arr.size())
                return 0;
            if (dp[i][last + 1] != -1)
                return dp[i][last + 1];

            int nottake = solve(i + 1, last, arr, difference, dp);
            int take = 0;
            if (last == -1 || arr[i] - arr[last] == difference)
                take = 1 + solve(i + 1, i, arr, difference, dp);

            return dp[i][last + 1] = max(take, nottake);
        }

    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
       	// memoization will not work as its O(N^2)

        unordered_map<int, int> m;
        int ans = 1;
        for (auto num: arr)
        {

            int curr = m.find(num - difference) != m.end()? 1 + m[num - difference]: 1;

            m[num]=curr;
            ans = max(ans, curr);
        }
        return ans;
    }
};