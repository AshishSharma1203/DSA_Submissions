class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       
        
        // use floyd's warshall algo 
      vector<vector<int>> grid(n,vector<int> (n,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
           grid[i][i]=0;
        }
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0], v=edges[i][1], wt=edges[i][2];
            grid[u][v]=wt;
            grid[v][u]=wt;
        }
        
        for(int node=0;node<n;node++)
        {
           for(int i=0;i<n;i++)
           {
               for(int j=0;j<n;j++)
               {
                   int from_node=grid[i][node];
                   int to_node=grid[node][j];
                   if(to_node==INT_MAX || from_node==INT_MAX )
                   {
                       continue;
                   }
                   else 
                   {
                       grid[i][j]=min(grid[i][j],to_node+from_node);
                   }
               }
           }
        }
        
      
		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (grid[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo; 
        
    }
};