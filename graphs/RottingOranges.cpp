class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int vis[n][m];

        // Initialize the visited array and push all initially rotten oranges to the queue
        for(int i = 0; i< n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;  // Marking rotten oranges as visited
                } else {
                    vis[i][j] = 0;  // Mark other cells as unvisited
                }
            }
        }

        int tm = 0;  // To track the maximum time taken
        int drow[] = {-1, 0, +1, 0};  // Row direction vectors
        int dcol[] = {0, 1, 0, -1};  // Column direction vectors

        // Perform BFS to rot all reachable fresh oranges
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Update the maximum time taken
            tm = max(t, tm);

            // Explore the 4 possible directions
            for(int i = 0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                // If the new position is within bounds and contains a fresh orange
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;  // Mark the fresh orange as rotten
                }
            }
        }

        // Check if there's any fresh orange left unrotted
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;  // Return -1 if any fresh orange is left unrotted
                }
            }
        }

        return tm;  // Return the time taken to rot all oranges
    }
};
