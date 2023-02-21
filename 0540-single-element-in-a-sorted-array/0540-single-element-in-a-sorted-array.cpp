class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       
        
        // ##    Note:our array size is always odd 
         // same elements index will be in pair like (0,1) (2,3) .. indexed elements would be same ideally 
        
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
            
            // check if mid is 0 or n-1 then this is our answer
            if(mid==0 || mid==n-1)  return nums[mid];
            
            // check if any of the  element before and after mid arent equal then it is ans
            
           if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
               return nums[mid];
            
            // if index of mid is even then ideally there are even elements in left part and being in pair they      would be  idential ,hence current mid element should be different 
            
            if(mid%2==0 && nums[mid]==nums[mid-1])
                high=mid-1;
            
            // if index of mid is odd then ideally there are odd elements in left part and being in pair they      would be  idential hence current mid element should match with previous one 
             
           else  if(mid%2!=0 && nums[mid]!=nums[mid-1])
            {
                high=mid-1;
            }
            
            // if both conditions fail then there is fault in right side of array 
            else 
                low=mid+1;
            
        }
        return nums[low];
        
    }
};