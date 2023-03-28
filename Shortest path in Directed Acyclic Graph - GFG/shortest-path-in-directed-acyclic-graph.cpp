//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        vector<int>distance (N,INT_MAX);
        distance[0]=0;
        
        
        vector<vector<pair<int,int>>> adj (N);
        
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0],v=edges[i][1],distance=edges[i][2];
            adj[u].push_back({v,distance});
        }
        
        queue<int> q;
        q.push(0);
        
        while(q.empty()==false)
        {
            int u=q.front();
            q.pop();
            // int curr_distance;
            
            for(auto it:adj[u])
            {
                int v=it.first,dist=it.second;
                int netdistance=distance[u]+dist;
                distance[v]=min(distance[v],netdistance);
                q.push(v);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends