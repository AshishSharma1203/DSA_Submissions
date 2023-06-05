class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
            string s1 = s;
            string s2 = s;

           	// for palindromic subsequence its same from start and end hence reverse one string and then apply               LCS  to find the required ans

            reverse(s2.begin(), s2.end());

           	// use LCS on both the strings 

           	// Tabulation method  

            vector<vector < int>> dp(n + 1, vector<int> (n + 1, 0));

            for (int i = 1; i <= n; i++)
            {

                for (int j = 1; j <= n; j++)
                {

                    if (s1[i - 1] == s2[j - 1])
                        dp[i][j] = 1 + dp[i - 1][j - 1];

                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            return n- dp[n][n];
        
    }
};