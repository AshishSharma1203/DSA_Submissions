//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  
//   recursive approach 

//   int solve(int day , vector<vector<int>>& points, int last_task)
//   {
      
//       if(day==0) 
//     {
//         // if it is last day then the result will be max of all the task excpet leaving the last performed task 
//         int curr_day= 0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last_task)
//             {
//                 curr_day=max(curr_day,points[0][i]);
//             }
//         }
//         return curr_day;
//     }
      
//       int ans=INT_MIN;
      
//       for(int i=0;i<3;i++)
//       {
//         //   at each day perform all the task except the prev day performed one 
          
//           if(i!=last_task)
//           {
//           int curr_day= points[day][i] + solve(day-1, points,i);  
//         //   update the ans with every task been performed 
//           ans= max(ans,curr_day);
//           }
//       }
//       return ans;
      
//   }
  
  int solve(int day, vector<vector<int>>& points,vector < vector < int > > &dp, int last_task)
  {
      if(dp[day][last_task]!=-1)
      return dp[day][last_task];
      
      if(day==0) 
    {
        // if it is last day then the result will be max of all the task excpet leaving the last performed task 
        int curr_day= 0;
        for(int i=0;i<3;i++)
        {
            if(i!=last_task)
            {
                curr_day=max(curr_day,points[0][i]);
            }
        }
        return dp[day][last_task]=curr_day;
    }
      
      int ans=INT_MIN;
      
      for(int i=0;i<3;i++)
      {
        //   at each day perform all the task except the prev day performed one 
          
          if(i!=last_task)
          {
          int curr_day= points[day][i] + solve(day-1, points,dp,i);  
        //   update the ans with every task been performed 
          ans= max(ans,curr_day);
          }
      }
      return dp[day][last_task]= ans;
      
      
  }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        
        vector < vector < int > > dp(n, vector < int > (4, -1));
        return solve(n-1,points,dp,3);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends