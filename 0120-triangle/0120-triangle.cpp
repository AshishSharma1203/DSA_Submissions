class Solution {
public:
    
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
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,0,n, triangle,dp);
        
    }
};