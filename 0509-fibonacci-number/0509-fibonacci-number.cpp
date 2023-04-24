class Solution {
public:
//     Recursive solution
    
//     int fib(int n) {
        
//         if(n==0 || n==1 ) 
//             return n; 
        
//         return fib(n-1)+fib(n-2);
        
//     }
    
    
    // memoization approach 
    
    int  solve(int n, vector<int> & dp)
    {
 
        if(n==0 || n==1 )
        {
           return dp[n]=n;
        }
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]= solve(n-1,dp)+ solve(n-2,dp);
    }
    
    int fib(int n) {
        
      vector<int> dp(n+1,-1);
       return  solve(n,dp);

    }
    
};