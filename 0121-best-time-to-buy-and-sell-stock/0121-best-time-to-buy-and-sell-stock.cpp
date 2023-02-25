class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int ans=0;
        int currmin=prices[0];
        for(int i=1;i<prices.size();i++)
        {
         if(prices[i]>currmin)
         {
             ans=max(ans,prices[i]-currmin);
             
         }
            currmin=min(currmin,prices[i]);
        }
        return ans;
    }
};