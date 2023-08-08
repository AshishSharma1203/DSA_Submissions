//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int x,int y,vector<vector<int>>&m,int n,vector<vector<bool>>&visited,vector<string> &ans,string &path)
    {
        
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        string dir="ULDR";
        
        for(int i=0;i<4;i++)
        {
            // left move
            int row=x+dx[i],col=y+dy[i];
            
            if(row>=0&& row<n && col>=0&& col<n && m[row][col]==1 && visited[row][col]==false)
            {
                visited[row][col]=true;
                path.push_back(dir[i]);
                solve(row,col,m,n,visited,ans,path);
                visited[row][col]=false;
                path.pop_back();
            }
            
        }
        
       
      
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]==0)
        return ans;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        string path="";
        visited[0][0]=true;
        solve(0,0,m,n,visited,ans,path);
        
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends