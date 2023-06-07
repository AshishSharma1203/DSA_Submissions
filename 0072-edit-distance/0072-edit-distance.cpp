class Solution
{
    public:

       	// Recursive approach 
        int solve(int i, int j, int n, int m, string s1, string s2)
        {
           	// base cases
            if (i == n)
                return m - j;
            if (j == m)
                return n - i;

           	// if matches
            if (s1[i] == s2[j])
                return solve(i + 1, j + 1, n, m, s1, s2);

           	// replace
            int way1 = 1 + solve(i + 1, j + 1, n, m, s1, s2);

           	// delete
            int way2 = 1 + solve(i + 1, j, n, m, s1, s2);

           	// insert
            int way3 = 1 + solve(i, j + 1, n, m, s1, s2);

            return min(way1, min(way2, way3));
        }

   	// Memoization approach 

    int mem_solve(int i, int j, int n, int m, string s1, string s2, vector<vector < int>> &dp)
    {
       	// base cases
        if (i == n)
            return m - j;
        if (j == m)
            return n - i;

        if (dp[i][j] != -1) return dp[i][j];

       	// if matches
        if (s1[i] == s2[j])
            return dp[i][j] = mem_solve(i + 1, j + 1, n, m, s1, s2,dp);

       	// replace
        int way1 = 1 + mem_solve(i + 1, j + 1, n, m, s1, s2,dp);

       	// delete
        int way2 = 1 + mem_solve(i + 1, j, n, m, s1, s2,dp);

       	// insert
        int way3 = 1 + mem_solve(i, j + 1, n, m, s1, s2,dp);

        return dp[i][j] = min(way1, min(way2, way3));
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
       	// return solve(0, 0, n, m, word1, word2);

        vector<vector < int>> dp(n, vector<int> (m, -1));
        return mem_solve(0, 0, n, m, word1, word2, dp);
    }
};