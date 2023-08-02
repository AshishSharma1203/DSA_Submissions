//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        
        if(A[0][0]==0)
        return -1;
        vector<vector<int>> dis(N,vector<int>(M,INT_MAX));
        
        dis[0][0]=0;
        
        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        
        
        // row,col
        queue<pair<int,int>>q;
        q.push({0,0});
        
        
        // use dijkstra algo 
        
        while(q.empty()==false)
        {
            int row=q.front().first, col=q.front().second;
            q.pop();
            
            int curr_dis=dis[row][col];
            // if(row==X && col==Y)
            // return curr_dis;
            
            for(int i=0;i<4;i++)
            {
                
                int x=row+dx[i],y=col+dy[i];
                
                if(x>=0 &&x<N && y>=0 && y<M && A[x][y]==1 && 1+ curr_dis < dis[x][y])
                {
                    dis[x][y]=1+ curr_dis;
                    q.push({x,y});
                }
            }
        }
        
        return dis[X][Y]==INT_MAX?-1:dis[X][Y];
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends