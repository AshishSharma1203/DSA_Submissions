class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
     
        int n=candies.size();
        int maxCandy=0;
        vector<bool>ans(n,false);
        
        for(auto i:candies)
            maxCandy=max(maxCandy,i);
        
        for(int i=0;i<n;i++)
        {
            
            if(candies[i]+extraCandies>=maxCandy)
            ans[i]=true;
        }
        
        return ans;
        
    }
};