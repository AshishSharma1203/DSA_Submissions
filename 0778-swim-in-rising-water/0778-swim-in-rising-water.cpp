class Solution {
public:
    
    bool bfs(vector< vector<int>>&grid, int k)
    {
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,-1,0,1};
        queue<pair<int,int>>q;
        // if(grid[0][0]<=k)
        q.push({0,0});
        
        while(q.empty()==false)
        {
            
            auto curr=q.front();
            q.pop();
            int x=curr.first, y=curr.second;
            if(x==n-1 && y==n-1)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int row=x+dx[i],col=y+dy[i];
                if(row>=0 && row<n && col>=0 && col<n && visited[row][col]==false)
                {
                    
                    if(grid[row][col]<=k)
                    {
                        q.push({row,col});
                        visited[row][col]=true;
                    }
                    
                }
            }
            
        }
        return false;
        
    }
    
    int swimInWater(vector<vector<int>>& grid) {
       
        int low=grid[0][0],high=2500,ans=low;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(bfs(grid,mid))
            {
                ans=mid;
                high=mid-1;
                
            }
            else 
                low=mid+1;
            
        }
        
        return ans;
        
    }
};