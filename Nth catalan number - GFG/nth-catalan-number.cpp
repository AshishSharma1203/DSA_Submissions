//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        
        vector<int> c(n+1,0);
        c[0]=c[1]=1;
        
        // int ans=0;
        int mod=(1e9+7); 
        for(int i=2;i<=n;i++)
        
        {
            long long  curr=0;
            for(int j=0;j<i;j++)
            {
                curr+=(c[j] *(1LL) *c[i-1-j]) % mod;
                curr=curr%mod;
            }
            
            c[i]=curr;
        }
        
        return c[n] % mod; 
        
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends