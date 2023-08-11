//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int solve(int i,int arr[],int n,int k,vector<int>&dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i]; 
        if(arr[i]-arr[i-1]<k)
        {
            return dp[i]=  max((arr[i]+arr[i-1] + solve(i+2,arr,n,k,dp)) , solve(i+1,arr,n,k,dp));
        } 
        else 
        return dp[i]=  solve(i+1,arr,n,k,dp); 
    }
    
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        
        sort(arr,arr+n);
        vector<int>dp(n,-1);
        return solve(1,arr,n,k,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends