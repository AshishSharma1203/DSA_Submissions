//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:


// memoization approach 
// bool solve(int i, vector<int> &arr, int sum, vector<vector<int>> &dp)
// {
    
//     if(i==0)
//     return arr[i]==sum ;
    
//     if(sum==0)
//     return true;
    
//     if(dp[i][sum]!=-1)  return dp[i][sum];
    
//   if(sum>= arr[i])
//   return  dp[i][sum]= solve(i-1,arr,sum-arr[i],dp) || solve(i-1, arr, sum,dp);
   
//   else 
//   return dp[i][sum]= solve(i-1,arr,sum,dp);
    
// }



    bool isSubsetSum(vector<int>arr, int sum){
        // code here
               int n=arr.size();
            //   vector<vector<int>> dp(n, vector<int> (sum+1,-1));
            //   return solve(n-1,arr,sum,dp);
            
            // tabulation approach 
            
            vector<vector<bool>>dp (n,vector<bool> (sum+1,false));
            dp[0][0]= true;
            for(int i=0;i<n;i++)
            dp[i][0]= true;\
            
            dp[0][arr[0]]= true;
            
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    
                    if(arr[i]<=j)
                    {
                        dp[i][j]= dp[i-1][j-arr[i]] || dp[i-1][j];
                    }
                    else 
                    dp[i][j]= dp[i-1][j];
                }
            }
            
            return dp[n-1][sum];
            
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends