class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> indegree (numCourses,0);
        
        vector<int> adj[numCourses];
          
        for(int i=0;i<prerequisites.size();i++)
        {
            int v=prerequisites[i][0];
            int u=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
       vector<int> ans;
        // if thre is no  cycle then count==numCourses i.e. toposort is possible 
        queue<int> q;
        
        for(int i=0;i<numCourses;i++)
        {

        if(indegree[i]==0)
            q.push(i);
        }
        
        while(q.empty()==false)
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            
            for(auto v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        if(ans.size()!=numCourses)
        {
            vector<int> temp;
            return temp;
        }
       return ans;
         
    }
};