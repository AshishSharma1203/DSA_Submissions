class Solution {
public:
    
   const int mod = 1000000007;

int solve(int countSong, int unique, int n, int goal, int k, vector<vector<int>>& dp)
{
    if (countSong == goal)
    {
        return unique == n;
    }

    if (dp[countSong][unique] != -1) {
        return dp[countSong][unique];
    }

    int ans = 0;

    if (unique < n) {
        // Play a unique song
        ans += (1LL * (n - unique) * solve(countSong + 1, unique + 1, n, goal, k, dp)) % mod;
        ans %= mod;
    }

    if (unique >= k) {
        // Replay
        ans += (1LL * (unique - k) * solve(countSong + 1, unique, n, goal, k, dp)) % mod;
        ans %= mod;
    }

    return dp[countSong][unique] = ans;
}

int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<int>> dp(goal + 1, vector<int>(n + 1, -1));
    int countSong = 0, unique = 0;
    return solve(countSong, unique, n, goal, k, dp);
}

};