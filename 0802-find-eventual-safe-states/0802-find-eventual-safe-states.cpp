class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      
        // reverse the edges  
        int V= graph.size();
        // int indegree[V]={0};
        vector<int> indegree (V,0);
        // vector<vector<int>> revgraph ;
        vector<vector<int>> revgraph (V);

        
        for(int i=0;i<V;i++)
        {

            for(auto v:graph[i])
            {
             revgraph[v].push_back(i);
                indegree[i]++;
            }
            
            
        }
        
        // now perform topo sort algo (Kahn's algo ) and store the nodes in vector 
      // the nodes that remain in vector are safe nodes 
    queue<int> q;
        vector<int> ans; 
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        
        while(q.empty()==false)
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto v: revgraph[curr])
            {
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans; 
    }
};