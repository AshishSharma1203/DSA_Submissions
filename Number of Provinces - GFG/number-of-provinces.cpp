//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
   void bfs(int u, vector<vector < int>> &isConnected, vector< bool > &visited)
        {

            queue<int> q;
            q.push(u);

            while (q.empty() == false)
            {

                int curr = q.front();
                q.pop();
                visited[curr] = true;

                for (int i = 0; i < isConnected[curr].size(); i++)
                {
                    if (isConnected[curr][i] == 1 && visited[i] == false)
                    {
                        q.push(i);
                    }
                }
            }
        }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        int ans = 0;
      

        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                bfs(i, adj, visited);
                ans++;
            }
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends