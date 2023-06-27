//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int ans=1;
    	
    	int curr_arrival= 1, curr_dept=0;
    	int count=1;
    	while(curr_arrival<n && curr_dept<n)
    	{
    	    if(arr[curr_arrival]<=dep[curr_dept])
    	    {
    	        count++;
    	        ans=max(ans,count);
    	        curr_arrival++;
    	    }
    	    else
    	    {
    	        count--;
    	        curr_dept++;
    	    }
    	}
    	return ans;
    	
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends