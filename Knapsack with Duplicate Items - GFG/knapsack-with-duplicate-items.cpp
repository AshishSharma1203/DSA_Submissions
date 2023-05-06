//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int solve(int i, int w, int val[], int wt[])
{
    if(i==0)
    {
        if(wt[0]<=w)
        return val[0];
        else 
        return 0;
    }
    
    if(wt[i]<=w)
    {
        return max(val[i] + solve(i, w-wt[i], val, wt ) , solve(i-1, w, val,wt));
    }
    
    else 
    return solve(i-1, w, val , wt);
    
}

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        //  return solve(N-1,W, val, wt);
        
        vector<vector<int>> dp(N, vector<int> (W+1,0));
        
        for(int i=wt[0]; i<=W; i++)
        {
        dp[0][i] = ((int) i/wt[0]) * val[0];
         }
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i]<=j)
                dp[i][j]= max(val[i] + dp[i][j-wt[i]] , dp[i-1][j]);
                else
                dp[i][j]= dp[i-1][j];
            }
        }
        
        return dp[N-1][W];
         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends