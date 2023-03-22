class Solution {
public:
    
    bool dfs(int i,bool col,vector<int>&color,vector<vector<int>> &graph)
    {
        
        color[i]=col;
        
        for(auto v:graph[i])
        {
            if(color[v]==col)
           return false;
            else if(color[v]==-1)
            {
                if(dfs(v,!col,color,graph)==false) return false;
            }
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        
        // coloring graph with 0 & 1 
       bool  col=0;
        
        for(int i=0;i<n;i++)
        {
          if(color[i]==-1)
          {
              if(dfs(i,col,color,graph)==false)
                  return false;
          }
        }
        return true;
    }
};