class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        
        int count= abs(n);
        
        while(count>0)
        {
            
            if(count%2==0)
            {
               x=x*x;
            }
            else if(count%2==1)
            {
                ans=ans*x;
                x=x*x;
            }
            count=count/2;
            
            
        }
        
        return n>=0?ans:1/ans;
        
    }
    
    
};