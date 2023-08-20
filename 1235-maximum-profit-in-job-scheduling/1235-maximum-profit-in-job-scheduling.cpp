class Solution {
public:
    
   static bool compare(vector<int>a,vector<int>b)
    {
        return a[0]<b[0];
    }
    
    int findIndex(int i, int end,vector<vector<int>>&time)
        
    {
        int n=time.size();
        for(int j=i+1;j<n;j++)
        {
            if(end<=time[j][0])
                return j;
        }
        return n;
        
    }
    
    int solve(int i,vector<vector<int>>&time,unordered_map<int,int>&dp)
    {
        
        if(i>=time.size())
            return 0;
        if(dp.find(i)!=dp.end())
            return dp[i];
        
        int ans=0;
        int nottake=solve(i+1,time,dp);
        
        int index=findIndex(i, time[i][1],time);
        int take= time[i][2]+ solve(index,time,dp);
        
        return dp[i]=  max(take,nottake);
        
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n=startTime.size();
        
        vector<vector<int>> time(n,vector<int>(3));
        
        for(int i=0;i<n;i++)
        {
            int u=startTime[i],v=endTime[i],w=profit[i];
            time.push_back({u,v,w});
        }
        
        sort(time.begin(),time.end(),compare);
        // vector<int>dp(n,-1);
        unordered_map<int,int>dp;
        return solve(0,time,dp);
        
    }
};