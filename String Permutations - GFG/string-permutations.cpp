//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(int i,string s, string &temp, vector<string>&ans, unordered_set<int>&st)
    {
        
        if(temp.size()==s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int j=0;j<s.size();j++)
        {
            if(st.find(j)==st.end())
            {
                temp.push_back(s[j]);
                st.insert(j);
                solve(j+1,s,temp,ans,st);
                temp.pop_back();
                st.erase(j);
            }
        }
        
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        string temp="";
        vector<string>ans;
        unordered_set<int>st;
        solve(0,s,temp,ans,st);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends