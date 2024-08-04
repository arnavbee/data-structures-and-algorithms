// class Solution {
// public:

// int m,n;


// int dp[101][101];

// int solve(vector<vector<int>>& grid, int i, int j){



//     if(i>=m || j >= n || grid[i][j] == 1)
//     return 0;

//     if(dp[i][j] != -1)
//     return dp[i][j];

//     if(i == m - 1 && j == n - 1)
//     return 1;



//     int right = solve(grid, i, j+1);
//     int down = solve(grid, i+1, j);

//     return dp[i][j] = right + down;
// }
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {

//     m = grid.size();
//     n = grid[0].size();
//     memset(dp, -1, sizeof(dp));
//     return solve(grid, 0, 0);
        
//     }
// };
