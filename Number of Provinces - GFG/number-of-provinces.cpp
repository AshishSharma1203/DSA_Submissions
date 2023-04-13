//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet
{
  
  public:
  vector<int> parent,size;
  
  DisjointSet(int n)
  {
      parent.resize(n);
      size.resize(n);
      
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
          size[i]=1;
      }
  }
  
  int findUparent(int node)
  {
      if(parent[node]==node)
      return node;
      
      return parent[node] = findUparent(parent[node]);
  }
  
//   void UnionBySize(int u,int v)
//   {
//       int par_u=findUparent(u),par_v=findUparent(v);
//       if(par_u==par_v) return ;
      
//       if(size[par_u]>size[par_v])
//       {
//           par_v=parent[par_u];
//           size[par_u]+=size[par_v];
//       }
//       else 
//       {
//           par_u=parent[par_v];
//           size[par_v]+=size[par_u];
//       }
//   }
    void unionBySize(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
  
};

class Solution {
  public:
  
  
//   using bfs 
//   void bfs(int u, vector<vector < int>> &isConnected, vector< bool > &visited)
//         {

//             queue<int> q;
//             q.push(u);

//             while (q.empty() == false)
//             {

//                 int curr = q.front();
//                 q.pop();
//                 visited[curr] = true;

//                 for (int i = 0; i < isConnected[curr].size(); i++)
//                 {
//                     if (isConnected[curr][i] == 1 && visited[i] == false)
//                     {
//                         q.push(i);
//                     }
//                 }
//             }
//         }
  
  
//   using dfs 
  
//   void dfs ( int i, vector<vector<int>> &adj, vector<bool> &visited)
//   {
       
//       visited[i]==true;
       
//       for(int j=0;j<adj[i].size();j++)
//       {
//           if(adj[i][j]==1 && visited[j]==false)
//           {
//               visited[j]=true;
//                 dfs(j,adj,visited);
//           }
          
//       }
       
//   }
  
//     int numProvinces(vector<vector<int>> adj, int V) {
//         // code here
        
//         int ans = 0;
      

//         vector<bool> visited(V, false);

//         for (int i = 0; i < V; i++)
//         {
//             if (visited[i] == false)
//             {
//                  ans++;
//                 // bfs(i, adj, visited);
//                 dfs(i, adj, visited);
               
//             }
//         }
//         return ans;
    
//     }

    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
      
      DisjointSet ds(V);
      for(int i=0;i<V;i++)
      {
          for(int j=0;j<V;j++)
          {
              if(i!=j && adj[i][j]==1)
              {
                  ds.unionBySize(i,j);
              }
          }
      }
      
      int ans=0;
      for(int i=0;i<V;i++)
      {
          if(ds.parent[i]==i)
          ans++;
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