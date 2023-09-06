class Solution
{
    public:
        int bulbSwitch(int n)
        {
//             if (n == 0 || n == 1)
//                 return n;

//             vector<int> bulbs(n + 1, 1);	// Initialize all bulbs as on

//             for (int i = 2; i <= n; i++)
//             {
//                 for (int j = i; j <= n; j += i)
//                 {
//                     bulbs[j] = !bulbs[j];	// Toggle the bulb state
//                 }
//             }

//             int ans = 0;
//             for (int i = 1; i <= n; i++)
//             {
//                 if (bulbs[i] == 1)
//                 {
//                     ans++;
//                 }
//             }

//             return ans;
            
            return sqrt(n);
        }
};