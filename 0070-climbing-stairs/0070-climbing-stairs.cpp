class Solution {
public:
    // Recursive Approach 
//     int climbStairs(int n) {
     
//         if(n==0 || n==1) return 1;
        
//         int way1= climbStairs(n-1);
//         int way2= climbStairs(n-2);
        
//         return way1+ way2;
        
//     }
    
    // memoization approach -------->>>> 
    
//     int solve(int n,vector<int> &dp)
//     {
//         if(n==0 || n==1) 
//             return dp[n]=1;
        
//         if(dp[n]!=-1)
//             return dp[n];
        
//         return solve(n-1,dp)+ solve(n-2,dp);
        
//     }
    
//       int climbStairs(int n) {
     
//         if(n==0 || n==1) return 1;
        
//           vector<int> dp(n+1,-1);
          
//          return  solve(n,dp);
      
//     }
    
    
    // tabulation approach ---------->>>>>>>>>>
    
      int climbStairs(int n) {
     
        if(n==0 || n==1) return 1;
        
        vector<int> dp(n+1,-1);
          dp[0]=dp[1]=1;
          
          for(int i=2;i<=n;i++)
              dp[i]=dp[i-1]+ dp[i-2];
          
          return dp[n];
        
    }
    
    
    
};