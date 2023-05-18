class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        
        int n= derived.size();
        vector<int> original (n);
        original [0]=0;
        
        for(int i=1;i<n;i++)
        {
            original[i]= original[i-1] ^ derived[i-1];
        }
        
        // bool ans;
        return (original[0] ^ original[n-1])==derived[n-1];
        
    }
};