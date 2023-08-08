class Solution {
public:
    
    void  solve(int i,string s,string temp, vector<string>&ans,unordered_set<string>&mp)
    {
        
      if(i==s.size())
      {
          temp.pop_back();
         ans.push_back(temp);
          return;
      }
        
        string curr="";
        for(int j=i;j<s.size();j++)
        {
            curr.push_back(s[j]);
            if(mp.find(curr)!=mp.end())
            {
                
                solve(j+1,s,temp+curr+" ",ans,mp);
                // temp.pop_back();
                // temp.pop_back();
               
            }
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        vector<string>ans;
        string temp="";
        unordered_set<string>mp(wordDict.begin(),wordDict.end());
        
        solve(0,s,temp,ans,mp);
        return ans;
        
    }
};