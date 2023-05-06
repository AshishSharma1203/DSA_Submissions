class Solution {
public:
    
    int solve(int i,vector<int> &nums, int target)
    {

        if(i==0)
        {
            if(target==0 && nums[0]==0)
                return 2;
            if(target+nums[0]==0 || target-nums[0]==0)
                return 1;
            else
                return 0;
        }
        
        int way1= solve(i-1, nums,target-nums[i]);
        int way2= solve(i-1, nums,target+nums[i]);
        
        return way1+ way2;
        
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n= nums.size();
    
        return solve(n-1,nums, target);
        
    }
};