//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
        // Code here
        // recursive code  
        
    //      if(n == 1) return 0;
    // int prevpath = INT_MAX;
    // for(int i = 1; i <= k; i++) {
        
    //     if(n-i>=1)
    //     {
           
    //     int currpath = minimizeCost(height, n - i, k) + abs(height[n-1] - height[n-1-i]);
    //     prevpath = min(prevpath, currpath); 
    //     }
        
    // }
    // return prevpath;

    int minimizeCost(vector<int>& height, int n, int k) 
    {
   
     vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 0;

    for(int i = 2; i <= n; i++)
    {
        int minstep = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 1)
            {
                minstep = min(minstep, dp[i-j] + abs(height[i-1] - height[i-j-1]));
            }
        }
        dp[i] = minstep;
    }

    return dp[n];

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends