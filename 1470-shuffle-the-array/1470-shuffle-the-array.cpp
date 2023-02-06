class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     
        vector<int> ans;
      
        
        for(int k=0;k< n;k++)
        {
            ans.push_back(nums[k]);
            ans.push_back(nums[n+k]);
        }
        
        return ans; 
    }
};