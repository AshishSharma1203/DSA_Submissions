class Solution {
public:
    
    bool solve(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
{
    
    if(i==0)
    return arr[i]==sum ;
    
    if(sum==0)
    return true;
    
    if(dp[i][sum]!=-1)  return dp[i][sum];
    
  if(sum>= arr[i])
  return  dp[i][sum]= solve(i-1,arr,sum-arr[i],dp) || solve(i-1, arr, sum,dp);
   
  else 
  return dp[i][sum]= solve(i-1,arr,sum,dp);
    
}
    
    bool canPartition(vector<int>& nums) {
        
        int sum= 0;
        int n= nums.size();
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(sum%2!=0) return false;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return solve(n-1,nums,sum/2,dp);
        
    }
};