class Solution {
public:
    int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // 1. Put every treasure in the queue first
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        // 2. One BFS spreading out from all treasures at once
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                // 3. Only step into in-bounds cells that haven't been reached yet
                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if(grid[nr][nc] != INF) continue;

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};