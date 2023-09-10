class Solution {
public:
    
   void  solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,int target)
    {
        int n=nums.size();
        if(i==n || target==0)
        {
            if(target==0)
                ans.push_back(temp);
            return ;
        }
        
        for(int j=i;j<n;j++)
        {
            if(j>i && nums[j]==nums[j-1])
                continue;
            
            if(nums[j]<=target)
            {
                temp.push_back(nums[j]);
                solve(j+1,nums,temp,ans,target-nums[j]);
                temp.pop_back();
            }
        }
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        
        solve(0,nums,temp,ans,target);
        return ans;
        
    }
};