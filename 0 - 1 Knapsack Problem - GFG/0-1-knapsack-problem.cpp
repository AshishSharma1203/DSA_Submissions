//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int i, int w, int val[], int wt[],vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(wt[i]<=w)
            return val[i];
            else 
            return 0;
        }
        
      if(dp[i][w] !=-1) return dp[i][w];
        
       if(wt[i]<=w)
       {
           return dp[i][w]=  max( solve(i-1, w, val, wt,dp) ,  (val[i] + solve(i-1, w-wt[i] , val, wt,dp)));
       }
       
       return  dp[i][w]=  solve(i-1, w, val, wt,dp);
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n,vector<int> (W+1,-1));
    
    //   return solve(n-1, W, val, wt, dp);
    
    vector<vector<int>> dp( n, vector<int> (W+1, 0));
    
    for(int i=wt[0];i<=W;i++)
    {
        dp[0][i] = val[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i] <= j)
            {
                dp[i][j] = max(dp[i-1][j],  val[i] + dp[i-1][j-wt[i]]);
            }
         
           else 
           dp[i][j]= dp[i-1][j];
            
        }
    }
    
    return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends