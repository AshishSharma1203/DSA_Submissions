//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int minThrow(int n, int arr[]) {
    std::unordered_map<int, int> mp;
    
    for (int i = 0; i < 2 * n; i += 2)
        mp[arr[i]] = arr[i + 1];
    
    std::vector<bool> visited(31, false);
    
    std::queue<std::pair<int, int>> q;
    q.push({0, 1}); // (steps, pos)
    visited[1] = true;
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int steps = curr.first;
        int pos = curr.second;
        
        if (pos == 30)
            return steps;
        
        for (int i = 1; i <= 6; i++) {
            int newPos = pos + i;
            
            if (newPos <= 30) {
                if (mp.find(newPos) != mp.end())
                    newPos = mp[newPos];
                
                if (!visited[newPos]) {
                    q.push({steps + 1, newPos});
                    visited[newPos] = true;
                }
            }
        }
    }
    
    return -1;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends