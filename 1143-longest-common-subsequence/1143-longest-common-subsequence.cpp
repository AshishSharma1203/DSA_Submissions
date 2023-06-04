class Solution
{
    public:

       	// Recursive approach  
        int solve(int i1, int i2, string s1, string s2)
        {

            if (i1 < 0 || i2 < 0) return 0;

           	// if both char matches, then move to remainaing part of strings 
            if (s1[i1] == s2[i2])
                return 1 + solve(i1 - 1, i2 - 1, s1, s2);

           	// if chars are disssmiliar then try matching with varying pointers  

            else
                return max(solve(i1 - 1, i2, s1, s2), solve(i1, i2 - 1, s1, s2));
        }

   	// memoization approach 

    int mem_solve(int i1, int i2, string s1, string s2, vector<vector < int>> &dp)
    {

        if (i1 < 0 || i2 < 0) return 0;

        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if(s1[i1]==s2[i2])
            return dp[i1][i2]= 1+ mem_solve(i1-1,i2-1, s1,s2,dp);
        
        else 
            return dp[i1][i2]= max(mem_solve(i1-1,i2,s1,s2,dp) , mem_solve(i1,i2-1, s1,s2,dp));
        
    }

    int longestCommonSubsequence(string text1, string text2)
    {

        // int i1 = text1.size() - 1, i2 = text2.size() - 1;

        int m = text1.size(), n = text2.size();
       	// return solve(i1,i2, text1,text2);
//         vector<vector < int>> dp(m, vector<int> (n, -1));

//         return mem_solve(i1, i2, text1, text2, dp);
        
        vector<vector<int>> dp(m+1, vector<int> (n+1,-1));
        
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {

                if(text1[i-1]==text2[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            
            }
        }
        
        return dp[m][n];
        
        
    }
};