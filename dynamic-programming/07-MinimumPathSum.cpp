// ### Approach 1: Rec + Memo

// class Solution {
// public:

// int dp[201][201];

// int solve(vector<vector<int>>& grid, int i , int j, int m , int n){
//     if(i == m - 1 && j == n -1)
//     return grid[i][j];

//     if(dp[i][j] != -1)
//     return dp[i][j];

//     if(i == m - 1)
//     return dp[i][j] = grid[i][j] + solve(grid, i, j+1, m, n);

//     if(j == n - 1)
//     return dp[i][j] = grid[i][j] + solve(grid, i + 1, j, m ,n);

//     else {
//         return dp[i][j] = grid[i][j] + min(solve(grid, i+1, j, m,n), solve(grid, i, j+1, m, n));
//     }
// }
//     int minPathSum(vector<vector<int>>& grid) {

//         memset(dp, -1, sizeof(dp));

//         int m = grid.size();
//         int n = grid[0].size();

//         return solve(grid,0,0,m,n);
//     }
// };

// ### Approach 2: Bottom's Up

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {

//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n));

//          // min path sum to reach from (0,0) to (i,j);

//          dp[0][0] = grid[0][0];

//          //fill 1st row

//          for(int col = 1; col<n; col++){
//             dp[0][col] = grid[0][col] + dp[0][col -1];
//          }

//         // fill 1 col

//         for(int row = 1; row < m; row++){
//             dp[row][0] = grid[row][0] + dp[row - 1][0]; 
//         }

//         // fill unaffected columns and rows

//         for(int i = 1; i<m; i++){
//             for(int j = 1; j<n; j++){
//                 dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
//             }
//         }

//         return dp[m-1][n-1];

        
//     }
// };