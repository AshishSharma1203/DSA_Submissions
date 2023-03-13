class Solution {
public:
    
    void bfs(int u,vector<vector<int>> & isConnected,vector<bool> &visited)
    {
        
        queue<int> q;
        q.push(u);
        
        while(q.empty()==false)
        {
  
            int curr=q.front();
            q.pop();
            visited[curr]=true;
           
            for(int i=0;i<isConnected[curr].size();i++)
            {
                if(isConnected[curr][i]==1 && visited[i]==false)
                {
                    q.push(i);
                }
            }
        
        }
        
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
    int ans=0;
   int v=isConnected.size();
        if(v==0) return ans; 
        
        vector<bool> visited (v,false);
        
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                bfs(i,isConnected,visited);
                ans++;
            }
        }
        return ans;
        
    }
};