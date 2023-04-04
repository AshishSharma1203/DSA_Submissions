class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         if(src==dst) return 0;
     vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        // quueue(stops,node,cost)
        queue<pair<int,pair<int,int>>>q;
        
        
        q.push({0,{src,0}});
        
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(q.empty()==false)
        {
            auto curr=q.front();
            q.pop();
            int stops=curr.first;
            int node=curr.second.first;
            int cost=curr.second.second;
            
            if (stops > k)
                continue;
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int nodePrice=it.second;
                
                if(cost+nodePrice <dist[adjNode]  && stops <= k)
                {
                    dist[adjNode]=cost+nodePrice;
                    q.push({stops+1,{adjNode,cost+nodePrice}});
                }
                
            }
            
        }
        
        if(dist[dst]==1e9)  return -1;
        return dist[dst];
        
    }
};