class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
          int n=nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int i;
        for( i=0;i<nums.size();)
        {
            
            if(i!=n-1 &&nums[i]!=nums[i+1])
            {
                ans.push_back(nums[i]);
                i++;
            }
            else 
            i+=2;
        }
        // cout<<ans.size();
        if(i>=n&& ans.size()==1)
        ans.push_back(nums[n-1]);
        return ans;
    }
};