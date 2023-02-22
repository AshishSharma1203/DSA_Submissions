class Solution {
public:
    
    int solve(vector<int> weights)
    {
        int sum=0;
        for(int i=0;i<weights.size();i++)
            sum+=weights[i];
        
        return sum; 
    }
    
    int check(vector<int>weights,int mid,int days)
    {
        int life=0;
        int currwt=0;
        
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>mid)  return -1;
          if(currwt+weights[i]>mid)
          {
              life++;
              currwt=weights[i];
          }
            else {
                currwt+=weights[i];
            }
        }
        life++;
        if(life>days)  return -1;
        return life;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        
        int ans=INT_MAX;
        int sum=solve(weights);
        
        int low=weights[0],high=sum;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int curr=check(weights,mid,days);
            // if(curr!=-1)  ans=min(ans,mid);
            // if(curr==-1)
            // {
            //     low=mid+1;
            // }
            // cout<<mid<<" "<<curr<<endl;
            if(curr!=-1)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans; 
        
    }
};