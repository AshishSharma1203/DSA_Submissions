class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int low=prices[0],high=0,res=0;
        for(int i=1;i<prices.size();i++){
            
            if(prices[i]>low){
                res=max(res,prices[i]-low);
            }
            else{
                low=prices[i];
            }
            
        }
        return res;
    }
};