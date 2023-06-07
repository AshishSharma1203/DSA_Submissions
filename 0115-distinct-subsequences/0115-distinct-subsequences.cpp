class Solution
{
    public:
        int mod = 1e9 + 7;
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
            return dp[i][j] = (mem_solve(i - 1, j - 1, s, t, dp) + mem_solve(i - 1, j, s, t, dp)) % mod;

        else
           	// here we need to reduce the i pointer to match the strng t with s 
            return dp[i][j] = mem_solve(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t)
    {

        int n = s.length(), m = t.length();
       	// vector<vector < int>> dp(n, vector<int> (m, -1));
       	// return mem_solve(n - 1, m - 1, s, t, dp);

       	// Tabulation appraoch
       	// here make dp array of n+1 size as we have to check for i-1 and j-1 also hence to avoid negative cases 
        vector<vector < int>> dp(n + 1, vector<int> (m + 1, 0));

       	// convert base cases 
       	// if(j < 0) return 1 ()
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;

                else
                    dp[i][j] = dp[i - 1][j] % mod;;
            }
        }

        return dp[n][m];
    }
};