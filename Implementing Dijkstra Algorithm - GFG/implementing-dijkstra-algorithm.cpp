//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // set (distance,node)
        set<pair<int,int>>s;
        s.insert({0,S});
        vector<int> ans (V,INT_MAX);
        ans[S]=0;
        
        while(s.empty()==false)
        {
            auto curr=*s.begin();
            s.erase(s.begin());
            int distance=curr.first,node=curr.second;
            
            for(auto it:adj[node])
            {
                int adjNode= it[0], weight=it[1];
                int currDistance=ans[node]+weight;
                if(currDistance<ans[adjNode])
                {
                    if(s.find({ans[adjNode],adjNode})!=s.end())
                    {
                        s.erase({ans[adjNode],adjNode});
                    }
                    ans[adjNode]=currDistance;
                    s.insert({currDistance,adjNode});
                }
            }
        }
        
        return ans; 
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends