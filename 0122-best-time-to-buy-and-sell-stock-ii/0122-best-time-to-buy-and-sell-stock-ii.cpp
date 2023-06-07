class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0;
        int min_price=prices[0];
        int curr_max=0;
        
        for(int i=1;i<prices.size();i++)
        {
            
           if(prices[i]>min_price)
           {
               ans+=prices[i]-min_price;
               min_price=prices[i];
           }
            else 
            {
                min_price=prices[i];
            }
            
        }
        return ans;
        
    }
};