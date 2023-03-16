class Solution {
public:
    
    void bfs(vector<vector<int>>&image,int sr,int sc,int color,int precolor)
    {
         
         int dx[] = { 1, 0,-1,0};
                
            int dy[] = { 0,1,0,-1};
              
            int m = image.size(), n = image[0].size();
        
        queue<pair<int,int>>q;
        q.push({sr,sc});

            while (q.empty() == false)
            {
                
                    auto curr = q.front();
                    q.pop();
                    int x = curr.first;
                    int y = curr.second;

                    for (int j = 0; j < 4; j++)
                    {
                        int row = x + dx[j];
                        int col = y + dy[j];
                        if (row >= 0 && row < m && col >= 0 && col < n && image[row][col] == precolor &&image[row][col]!=color)
                        {
                            image[row][col] = color;
                            q.push({row,col});
                        }
                    }
                
            }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int m=image.size(),n=image[0].size();
        
        if(image[sr][sc]==color)  return image;
        int precolor=image[sr][sc];
        
        image[sr][sc]=color;
        
        bfs(image,sr,sc,color,precolor);
        
        return image;
        
    }
};