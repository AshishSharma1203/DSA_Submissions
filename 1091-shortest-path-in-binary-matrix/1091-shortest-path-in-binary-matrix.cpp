class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        
        // Use Djikstra's Algo to find the the shortest distance 
    if(grid[0][0] == 1) return -1;

    int n=grid.size();
    vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
    distance[0][0]=1;

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push({0,0});

    vector<pair<int,int>> dir ={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};

    while(!pq.empty()) {
        auto curr=pq.top();
        pq.pop();
        int x=curr.first, y=curr.second;

        if(x == n-1 && y == n-1) return distance[n-1][n-1];

        for(int i=0;i<8;i++) {
            int dx=dir[i].first,dy=dir[i].second; 
            int row=x+dx, col=y+dy;
            if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col]==0) {
                int curr_distance=distance[x][y]+1;
                if(curr_distance < distance[row][col]) {
                    // it means it is shortes path to reach the following cell of grid, hence update it 
                    distance[row][col] = curr_distance;
                    pq.push({row, col});
                }
            }
        }
    }
// if queue becomes then we cant reach to bottom-right position 
    return -1;
}
};