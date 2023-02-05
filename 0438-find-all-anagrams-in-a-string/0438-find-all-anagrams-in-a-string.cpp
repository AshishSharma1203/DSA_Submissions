class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      
        vector<int> ans ;
        if(p.size()>s.size()) return ans; 
        
        vector<char> v1(26,0);
        for(int i=0;i<p.size();i++)  v1[p[i]-'a']++;
        
        for(int i=0;i<=s.size()-p.size();i++) 
        {
            vector<char> v2(26,0);
            for(int j=i;j<p.size()+i;j++)
            {
                v2[s[j]-'a']++;
            }
            if(v1==v2) ans.push_back(i);
        }
        return ans; 
        
    }
};