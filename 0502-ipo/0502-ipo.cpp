class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n=profits.size();
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profits[i]});
        }
        
        sort(v.begin(),v.end());   // sort it in order of increasing capital 
        
        int index=0;
        priority_queue<int> max_capitals;
        while(k--)
        {
            
            while(index<n && v[index].first<=w)
            {
                max_capitals.push(v[index].second);
                index++;
            }
            
            // check if priority queue isn't empty
            if(max_capitals.empty()==true)  break;
            
            w+=max_capitals.top();
            max_capitals.pop();
            
        }
        
        return w;
        
        
    }
};