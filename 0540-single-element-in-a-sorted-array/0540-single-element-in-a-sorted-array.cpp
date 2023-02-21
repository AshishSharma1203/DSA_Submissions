class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       
        
        int ans=-1;
        if(nums.size()==1)  return nums[0];
        
        for(int i=1;i<nums.size();i=i+2)
        {
            if(nums[i]!=nums[i-1])  
                return nums[i-1];
        }
        return nums[nums.size()-1];
        
    }
};