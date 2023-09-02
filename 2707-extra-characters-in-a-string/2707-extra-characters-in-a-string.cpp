class Solution
{
    public:

//         int solve(int i, string s, unordered_set<string> &st, vector<int> &dp)
//         {

//             if (i == s.size())
//                 return 0;

//             if (dp[i] != -1)
//                 return dp[i];

           
//             int way1 = 0 + solve(i + 1, s, st, dp);
//             int way2 = 0;
//             for (int j = i; j < s.size(); j++)
//             {

//                 string s1 = s.substr(i, j - i + 1);
//                 if (st.find(s1) != st.end())
//                 {
                    
//                     way2 = s1.size() + solve(j + 1, s, st, dp);
                    
//                 }
//             }

//             return dp[i] = max(way1, way2);
//         }

//     int minExtraChar(string s, vector<string> &dictionary)
//     {

//         unordered_set<string> st(dictionary.begin(), dictionary.end());

//         vector<int> dp(s.size(), -1);
//         int matched = solve(0, s, st, dp);

//         return s.size() - matched;
//     }
    
    unordered_map<string,int> mp;
    int n;
    int solve(string &s,int idx,vector<int> &dp){
        if(idx>=n){
            return 0;
        }
        
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        //ignoring current index(not picking)
        string temp="";
        int ans=solve(s,idx+1,dp);

        //considering all possible strings(multiple picks)
        for(int i=idx ; i<n ; i++){
            temp+=s[i];
            if(mp[temp]){
                ans=max(ans,(int)temp.size()+(int)solve(s,i+1,dp));
            }
        }
        
        return dp[idx]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.size();
        vector<int> dp(n+1,-1);
        for(auto e : dictionary){
            mp[e]=1;
        }
        return n-solve(s,0,dp);
    }
};