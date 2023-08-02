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
        
        // vector<vector<int>> dis(N,vector<int>(M,INT_MAX));
        vector<vector<bool>> vis(N,vector<bool>(M,false));
        vis[0][0]=true;
        
        // dis[0][0]=0;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        
        while(!q.empty())
        {
            
            int curr_dis=q.front().first, row=q.front().second.first,col=q.front().second.second;
            q.pop();
            
            
            if(row==X and col==Y)
            return curr_dis;
        
            
            for(int i=0;i<4;i++)
            {
                
                int x=row+dx[i], y=col+dy[i];
                if(x>=0 && x<N &&  y>=0 && y<M && A[x][y]==1 && vis[x][y]==false )
                {
                    q.push({1+curr_dis,{x,y}});
                    vis[x][y]=true;
                }
                
            }
            
        }
        
        return -1;
        
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