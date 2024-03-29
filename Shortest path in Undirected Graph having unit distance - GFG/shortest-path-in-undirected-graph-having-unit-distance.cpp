//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>distance (N,INT_MAX);
        distance[src]=0;
        vector<bool>  visited (N,false);
        
        vector<vector<int>> adj (N);
        
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        
        while(q.empty()==false)
        {
            int u=q.front();
            q.pop();
            // int curr_distance;
            visited[u]=true;
            for(auto it:adj[u])
            {
                if(visited[it]==false)
                {
                    int d=distance[u]+1;
                distance[it]=min(d,distance[it]);
                q.push(it); 
                }
               
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(distance[i]==INT_MAX)
            distance[i]=-1;
        }
        
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends