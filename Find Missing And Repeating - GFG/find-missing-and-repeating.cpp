//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
       int xors = 0;
    for (int i = 0; i < n; i++) {
        xors ^= arr[i] ^ (i + 1);
    }

    int set_bit = 0;
    int i = 1;
    while (true) {
        if (xors & i) { // Change from (xors & i == 1) to (xors & i)
            break;
        }
        i = i << 1;
        set_bit++;
    }

    int bit_1 = 0, bit_0 = 0;

    for (int i = 0; i < n; i++) {
        if ((arr[i] >> set_bit) & 1) { // Change from (arr[i] >> set_bit == 1) to ((arr[i] >> set_bit) & 1)
            bit_1 ^= arr[i];
        } else {
            bit_0 ^= arr[i];
        }
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (i & (1 << set_bit)) {
            bit_1 ^= i;
        } else {
            bit_0 ^= i;
        }
    }
    
    // run a loopp and check if a[i]==zero , then count++ , if(count==2) then it is repaeting 
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==bit_0)
        count++;
    }
    
    if(count==2)
    return {bit_0,bit_1};
    else 
    return {bit_1, bit_0};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends