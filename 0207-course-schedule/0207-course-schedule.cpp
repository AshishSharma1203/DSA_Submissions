class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // use cycle detection algo (Kahn's Algo ) of graph 
        // if there is cycle then return false 
        
          
        vector<int> indegree (numCourses,0);
        
        vector<int> adj[numCourses];
          
        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        int count=0;
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
            count++;
            
            for(auto v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        
        if(count==numCourses)  return true;
        return false;
        
    }
};