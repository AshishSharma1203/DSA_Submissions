class Solution
{
    public:

        bool solve(int i, vector<int> &arr, vector<bool> &visited)
        {

            if (arr[i] == 0)
                return true;

            visited[i] = true;

            bool way1 = false, way2 = false;

            if (i + arr[i] < arr.size() && visited[i + arr[i]] == false)
            {
                way1 = solve(i + arr[i], arr, visited);
            }

            if (i - arr[i] >= 0 && visited[i - arr[i]] == false)
                way2 = solve(i - arr[i], arr, visited);

            return way1 || way2;
        }

    bool canReach(vector<int> &arr, int start)
    {

        int n = arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;
        return solve(start, arr, visited);
    }
};