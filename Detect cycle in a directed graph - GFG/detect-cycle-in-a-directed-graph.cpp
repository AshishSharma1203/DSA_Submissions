//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // use kahn's algo to detect cycle
        
        bool visited[V]={false};
        int indegree[V]={0};
        
        for(int i=0;i<V;i++)
        {
            for(auto  it:adj[i])
            indegree[it]++;
        }
        
    //   vector<int> toposort;
    int count=0;
       queue<int>q;
       for(int i=0;i<V;i++)
       {
           if(indegree[i]==0)
           {
               q.push(i);
           }
       }
       
       while(q.empty()==false)
       {
           int curr=q.front();
           q.pop();
        //   toposort.push_back(curr);
        count++;
           
           for(auto v:adj[curr])
           {
               indegree[v]--;
               if(indegree[v]==0)
               q.push(v);
           }
       }
        
       if(count==V) return false;
       return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends