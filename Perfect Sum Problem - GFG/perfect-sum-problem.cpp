//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    // int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    // int taken = 0;
    // if(arr[ind]<=target)
    //     taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    // return dp[ind][target]= (notTaken + taken)% (int)(1e9 + 7);
    
    if(arr[ind]<=target)
    {
    dp[ind][target]= (findWaysUtil(ind-1,target,arr,dp) + findWaysUtil(ind-1,target-arr[ind],arr,dp))% (int)(1e9 + 7);
    }
    else 
    {
        return dp[ind][target]= findWaysUtil(ind-1,target,arr,dp) % (int)(1e9 + 7);
    }
	}
	
	int solve(int i, int arr[], int sum)
	{
	    if(i==0)
	    {
	       // here we need do check if the first elelment is 0 & target ==0, if it is then there are two ways
	       // either include it or not the sum remains uneffected 
	       
	       if(sum==0 && arr[0]==0)
	       return 2;
	       if(sum==0) return 1;
	       return sum ==arr[0]?1:0;
	       
	    }
	    
	    
	    
	    if(sum==0) return 1;
	   // if(target<0)  return 0;
	    
	    if(arr[i]<=sum)
	    {
	        return (solve(i-1, arr, sum-arr[i]) + solve(i-1, arr, sum))% (int)(1e9 + 7) ;
	    }
	    else 
	    return solve(i-1, arr, sum) % (int)(1e9 + 7); 
	    
	}
	
	
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return findWaysUtil(n-1,sum,arr,dp);
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends