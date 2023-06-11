class Solution {
public:
    
//     int solve(int i, int last, vector<int> &nums, vector<int> hash)
//     {
        
//         if(i==n) return 0;
        
        
//     }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
      int n= nums.size();
      sort(nums.begin(),nums.end());
        vector<int> dp(n,1), hash(n,1);
        
        for(int i=0;i<n;i++)
        {

            hash[i]=i;
            
            for(int prev_ind=0;prev_ind<=i-1;prev_ind++)
            {
                
                if(nums[i] % nums[prev_ind]==0)
                {

                    if(1+ dp[prev_ind] > dp[i])
                    {
                        dp[i]= 1+dp[prev_ind];
                        hash[i]=prev_ind;
                    }
                
                }
                
            }
        
        }
        
        int ans=-1, last_ind=-1;
        for(int i=0;i<n;i++)
        {
            
            if(dp[i]> ans)
            {
                ans=dp[i];
                last_ind= i;
            }
            
        }
        
        vector<int> temp;
        temp.push_back(nums[last_ind]);
        
        while(hash[last_ind]!=last_ind)
        {
            last_ind=hash[last_ind];
            temp.push_back(nums[last_ind]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp; 
    }
};