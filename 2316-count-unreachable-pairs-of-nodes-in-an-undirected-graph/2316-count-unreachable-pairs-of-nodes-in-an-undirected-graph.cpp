class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> adj[n];

        //Creating adjacency list
        for(long long i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long cntc=0,cntdis=0,res=0;

        //true for visited nodes 
        vector<bool> vis(n,false);

        //queue for bfs approach
        queue<long long> q;


        //for loop for traversing different components of graph
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);

                //bfs: 
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    cntc++;
                    vis[t]=true;
                    for(int i=0;i<adj[t].size();i++){
                        if(!vis[adj[t][i]]){
                            q.push(adj[t][i]);
                            vis[adj[t][i]]=true;
                        }
                    }
                    cntdis=n-cntc;
                }
                res+=cntdis*cntc;
            }
            cntc=0;
        }

        return res/2;
    }
};