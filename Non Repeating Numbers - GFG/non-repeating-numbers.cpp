//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i;
        for( i=0;i<nums.size();)
        {
            
            if(i!=n-1 &&nums[i]!=nums[i+1])
            {
                ans.push_back(nums[i]);
                i++;
            }
            else 
            i+=2;
        }
        // cout<<ans.size();
        if(i>=n&& ans.size()==1)
        ans.push_back(nums[n-1]);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends