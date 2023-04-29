class Solution {
public:
    
    // Recursive approach 
    
//     int solve(int i,int j,int m,int n)
//     {
//         if(i==m-1 && j==n-1)
//             return 1;
//         if(i>=m ||  j>=n)
//             return 0;
        
//         int down= solve(i+1,j, m,n);
//         int right= solve(i,j+1,m,n);
        
//         return down+right;
        
//     }
    
    
    // memoization approach     
    
    int solve(int i,int j,int m,int n, vector<vector<int>> &dp)
    {
        
        if(i==m-1 && j==n-1 )
        {
            return 1;
        }
        if(i>=m || j>= n)
            return 0;
        
        if(dp[i][j]!=0)
            return dp[i][j];
          int down= solve(i+1,j, m,n,dp);
        int right= solve(i,j+1,m,n,dp);
        
        return dp[i][j]= down+right;
    }
    
    
    int uniquePaths(int m, int n) {
          
        // vector<vector<int>> dp(m, vector<int> (n,0));
        
        // return solve(0,0,m,n,dp);
        
        // tabulation approach 
        
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int j=0;j<n;j++)
            dp[0][j]=1;
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
              // dp[i][j]= sum of ways to reach its adjacent left cel + up cell 
                dp[i][j]= dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return dp[m-1][n-1];
        
    }
};