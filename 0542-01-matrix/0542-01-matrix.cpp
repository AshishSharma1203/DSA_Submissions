class Solution
{
    public:

        void bfs(queue<pair<pair<int,int>,int>>q, vector<vector < int>> &visited, vector< vector< int >> &ans, vector< vector< int>> &mat)
        {
            int m=mat.size(),n=mat[0].size();
            
            int dx[4]={-1,0,1,0};
            int dy[4]={0,-1,0,1};
            
            while(q.empty()==false)
            {
                auto curr=q.front();
                int i=curr.first.first;
                int j=curr.first.second;
                int distance=curr.second;
                q.pop();
                visited[i][j]=1;
                // ans[i][j]=distance;
                
                if(mat[i][j]==1)
                {
                    ans[i][j]=distance;
                    // q.push({{i,j}})
                }
                
                // ans[i][j]=distance;
                
                    for(int k=0;k<4;k++)
                    {
                        int row=i+dx[k];
                        int col=j+dy[k];
                        if(row>=0&& row<m && col>=0&& col<n && visited[row][col]==0)
                        {
                            q.push({{row,col},distance+1});
                            visited[row][col]=1;
                        }
                    }
                
            }
            
        }

    vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
    {

        int m = mat.size(), n = mat[0].size();
        vector<vector < int>> ans(m, vector<int> (n, 0));
        vector<vector < int>> visited(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(mat[i][j]==0)
                q.push({{i,j},0});
		
            }
        }

        bfs(q, visited, ans, mat);
        return ans;
    }
};