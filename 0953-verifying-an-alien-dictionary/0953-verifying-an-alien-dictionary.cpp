class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i=0;i<order.size();i++) mp[order[i]] = i;
        for(int i=1;i<words.size();i++) {
            string str1 = words[i-1];
            string str2 = words[i];
            int x = 0, y = 0;
            while(x < str1.length() && y < str2.length()) {
                if(str1[x] == str2[y]) {
                    x++; y++;
                }else {
                   if(str1[x] != str2[y] && mp[str1[x]] > mp[str2[y]]) {
                        return false;
                    }else break;
                }
            }
            if(x < str1.length() && y == str2.length()) return false;
        }
        return true;
    }
};