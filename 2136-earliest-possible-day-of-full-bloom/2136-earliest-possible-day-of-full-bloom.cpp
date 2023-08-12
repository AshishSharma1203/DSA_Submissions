class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        vector<pair<int,int>>arr;
        for(int i=0;i<plantTime.size();i++)
        {
            arr.push_back({growTime[i],plantTime[i]});
        }
        sort(arr.begin(),arr.end(), greater<pair<int, int>>());
        
        int ans=0;
        int lastPlant=0;
        for(int i=0;i<arr.size();i++)
        {
            
           lastPlant+=arr[i].second;
            ans=max(ans,lastPlant+arr[i].first);
        }
        return ans;
    }
};