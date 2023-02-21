class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       
       // brute force 
        // our array size is always odd 
//         int ans=-1;
//         if(nums.size()==1)  return nums[0];
        
//         for(int i=1;i<nums.size();i=i+2)
//         {
//             if(nums[i]!=nums[i-1])  
//                 return nums[i-1];
//         }
//         return nums[nums.size()-1];
        
        int n=nums.size();
        int low=0,high=n-1;
        int ans=-1;
        
        if(n==1)  return nums[0];
        
        while(low<high)
        {
         int mid=(low+high)/2;
            if(mid==0 || mid==n-1)  return nums[mid];
           if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==0 && nums[mid]==nums[mid-1]){
                high=mid-1;
            }
             
           else  if(mid%2!=0 && nums[mid]!=nums[mid-1])
            {
                high=mid-1;
            }
            else 
                low=mid+1;
            
        }
        return nums[low];
        
    }
};