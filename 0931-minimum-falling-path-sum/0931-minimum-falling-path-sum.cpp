class Solution {
public:
    
    int solve(int i,int j, int n, vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        if(i>=n || i<0 || j>=n || j<0)
            return 1e9;
        if(i==n-1)
            return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        
        int down= solve(i+1,j,n,matrix,dp);
        int downleft=solve(i+1,j-1,n,matrix,dp);
        int downright=solve(i+1,j+1,n,matrix,dp);
        
        return  dp[i][j]=  matrix[i][j]+min(down, min(downleft,downright));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        int n= matrix.size();
        
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
        {
            int curr_ans= solve(0,i,n,matrix,dp);
            ans= min(ans,curr_ans);
        }    
        
        return ans;
    }
};