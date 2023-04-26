//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
// 	recursive approcah 

//  int findMaxSum(int *arr, int n) {
// 	    // code here
// 	     if(n<0) return 0;
// 	    if (n==1) return arr[0];
// 	   // if(n==1) return arr[1];
	   
// 	    int take= findMaxSum(arr, n-2) + arr[n-1];
// 	    int notTake= 0 + findMaxSum(arr, n-1);
	    
// 	    return max(take,notTake);
	    
// 	} 
	
	int solve( int n, int *arr,vector<int>& dp)
	{
	    if(n==0) 
	    return arr[0];
	    if(n<0) return 0;
	    
	    if(dp[n]!=-1)
	    return dp[n];
	    
	    int take = arr[n]+ solve(n-2, arr,dp);
	    int notTake= solve(n-1, arr,dp);
	    
	    return dp[n]= max(take,notTake);
	    
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	   
	   vector<int> dp(n,-1);
	   
	   return solve( n-1, arr,dp);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends