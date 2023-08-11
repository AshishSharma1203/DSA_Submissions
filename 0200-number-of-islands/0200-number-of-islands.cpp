class Solution {
public:
    
    
    void dfs(int i,int j, vector<vector<char>>&grid, vector<vector<bool>>&visited)
    {
        int m=grid.size(),n=grid[0].size();
        
        if(i<0 ||i>=m || j<0 ||j>=n || grid[i][j]=='0' || visited[i][j]==true)
            return;
         visited[i][j]=true;
        // grid[i][j]='0';
         dfs(i-1,j,grid,visited);
         dfs(i+1,j,grid,visited);
         dfs(i,j-1,grid,visited);
         dfs(i,j+1,grid,visited);
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size(),n=grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==false)
                {
                  ans++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
        
    }
};