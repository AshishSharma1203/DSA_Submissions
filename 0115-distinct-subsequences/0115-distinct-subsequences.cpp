class Solution
{
    public:

       	// Recursive approach 
        int solve(int i, int j, string s, string t)
        {
            if (j < 0) return 1;
            if (i < 0) return 0;

            if (s[i] == t[j])
                return solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
            else
                return solve(i - 1, j, s, t);
        }

   	// Memoization approach

    int mem_solve(int i, int j, string s, string t, vector<vector < int>> &dp)
    {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
           	// take the current char at i in s, or we can try to search on left part of s string 
            return dp[i][j] = mem_solve(i - 1, j - 1, s, t, dp) + mem_solve(i - 1, j, s, t, dp);

        else
           	// here we need to reduce the i pointer to match the strng t with s 
            return dp[i][j] = mem_solve(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t)
    {

        int n = s.length(), m = t.length();
        vector<vector < int>> dp(n, vector<int> (m, -1));
        return mem_solve(n - 1, m - 1, s, t, dp);
    }
};