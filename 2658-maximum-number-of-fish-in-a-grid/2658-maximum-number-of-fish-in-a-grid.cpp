class Solution {
public:
    
    int solve(int i,int j, vector<vector<int>> & grid,  vector<vector<bool>> &visited)
    {
          int m= grid.size(), n=grid[0].size();
         int dx[]={-1,0,1,0};
        int dy[]= {0,-1,0,1};
         queue<pair<int,int>> q;
        q.push({i,j});
        
        int ans=0;
        
          while(q.empty()==false)
        {
            auto curr= q.front();
            q.pop();
            int row= curr.first;
            int col= curr.second;
            ans+=grid[row][col];
            visited[row][col]= true;
        
            
            for(int k=0;k<4;k++)
            {
                int nrow=row+ dx[k];
                int ncol= col+ dy[k];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]!=0 && visited[nrow][ncol]==false)
                    
                {
                  visited[nrow][ncol]=true;
                    q.push({nrow,ncol} );
                }
                
            }
            
        }
        
        return ans;
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m= grid.size(), n=grid[0].size();
        int ans=0;
        
       
        
       
       vector<vector<bool>> visited (m, vector<bool> (n,false));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0 && visited[i][j]==false )
                {
                    int curr_fish=solve(i,j,grid, visited);
                    ans=max(ans,curr_fish);
                     // q.push({{i,j},grid[i][j]});
                    // visited[i][j]=true;
                }
                   
              
            }
        }
        
        // perform bfs 
        
      
        
        return ans; 
        
    }
};