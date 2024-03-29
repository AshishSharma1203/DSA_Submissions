//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void bitManipulation(int num, int i) {
    // Get ith bit
    int bit = (num >> (i-1)) & 1;
    cout << bit << " ";
    
    // Set ith bit
    num = num | (1 << (i-1));
    cout << num << " ";
    
    // Clear ith bit
    num = num & ~(1 << (i-1));
    cout << num << " ";
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends