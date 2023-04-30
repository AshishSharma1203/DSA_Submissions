class Solution {
public:
    
    // memoization approach 
    
    int solve(int i,int j,  int n,vector<vector<int>>& triangle, vector<vector<int>> &dp)
    {

    if(j>i || i>=n) return 100001;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(i==n-1)
            return triangle[i][j];
        
        int nextrow= solve(i+1,j,n, triangle,dp);
        int nextAdjacentrow= solve(i+1,j+1,n, triangle,dp);
        
        return dp[i][j]= triangle[i][j] + min(nextrow, nextAdjacentrow);
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve(0,0,n, triangle,dp);
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]= triangle[0][0];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                // if(j>i)
                //     continue;
                
                if(j==0)
                    dp[i][j]= triangle[i][j]+ dp[i-1][j];
                
                else if(j==i)
                    dp[i][j]=triangle[i][j]+ dp[i-1][j-1];
                else 
                {
                    dp[i][j]= triangle[i][j] + min(dp[i-1][j] , dp[i-1][j-1]);
                }
                
            }
        }
        
        int ans= INT_MAX;
        
        for(int i=0;i<n;i++)
            ans= min(ans,dp[n-1][i]);
        
        return ans; 
        
    }
};

