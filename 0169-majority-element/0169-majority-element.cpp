class Solution
{
    public:
        int majorityElement(vector<int> &nums)
        {

           	// approach 1: use two for loops 
           	// approach 2 : use map 

           	// optimal approach 
            
            // Using Moorey Voting Algo 
            
            int n= nums.size();
            int ans= nums[0];
            int count=1;
            for(int i=1;i<n;i++)
            {
                
                if(nums[i]==ans)
                {
                    count++;
                }
                else
                {
                    count--;
                }
                if(count==0)
                {
                    ans= nums[i];
                    count=1;
                }
                
            }
            return ans; 

        }
};